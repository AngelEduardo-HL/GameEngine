#pragma once

struct EventData {
	// Add event data members here

};

class EventListener;

class EventBus {
public:
	static EventBus& get() {
		static EventBus instance;
		return instance;
	}

private:
	EventBus() = default;

	struct Listener {
		int id = 0;
		EventListener* listener = nullptr;
	};

	int nextID = 0;
};

class EventListener {
public:
	virtual ~EventListener() = default;
};
