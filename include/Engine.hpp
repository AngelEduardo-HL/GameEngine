#ifndef SKIBIDI_ENGINE_HPP
#define SKIBIDI_ENGINE_HPP

#include "scene_manager.hpp"

namespace skibidi
{
    class Engine
    {
    public:

        Engine() = default;
        ~Engine() = default;


        void Init();

        void Run();

        void Update();
        void Draw();

        void Shutdown();


        SceneManager& sceneMgr =
            SceneManager::get();


        int screenWidth = 800;
        int screenHeight = 600;
    };
}

#endif