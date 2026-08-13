#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

// Contenedor universal de datos simple y plano
struct EventData {
    std::string type = "";
    std::string name = "";
    std::string tag = "";
    int intVal = 0;
    float floatVal = 0.0f;
    bool boolVal = false;
};

class EventListener;


class EventBus {
public:
    static EventBus& get() {
        static EventBus instance;
        return instance;
    }

    int listen(const std::string& event, EventListener* listener);
    void unbind(const std::string& event, int id);
    void fire(const std::string& event, EventData data = {});

private:
    EventBus() = default;

    struct Listener {
        int id = 0;
        EventListener* listener = nullptr;
    };

    int nextId = 0;
    std::unordered_map<std::string, std::vector<Listener>> listeners;
};


class EventListener {
public:
    virtual ~EventListener();
    virtual void onEvent(EventData data) = 0;

protected:
    void listen(const std::string& event);

private:
    struct Subscription {
        std::string event;
        int id;
    };

    std::vector<Subscription> subscriptions;
};


inline int EventBus::listen(const std::string& event, EventListener* listener) {
    int id = ++nextId;
    listeners[event].push_back({ id, listener });
    return id;
}

inline void EventBus::unbind(const std::string& event, int id) {
    auto it = listeners.find(event);
    if (it == listeners.end()) return;

    auto& list = it->second;

    for (std::size_t i = 0; i < list.size(); ++i) {
        if (list[i].id == id) {
            list[i] = list.back();
            list.pop_back();

            if (list.empty()) {
                listeners.erase(it);
            }

            return;
        }
    }
}

inline void EventBus::fire(const std::string& event, EventData data) {
    auto it = listeners.find(event);
    if (it == listeners.end()) return;

    data.type = event;

    auto list = it->second;

    for (const auto& entry : list) {
        if (entry.listener) {
            entry.listener->onEvent(data);
        }
    }
}

inline EventListener::~EventListener() {
    for (const auto& sub : subscriptions) {
        EventBus::get().unbind(sub.event, sub.id);
    }
}

inline void EventListener::listen(const std::string& event) {
    int id = EventBus::get().listen(event, this);
    subscriptions.push_back({ event, id });
}