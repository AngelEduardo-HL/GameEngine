#pragma once

namespace skibidi
{
    class Scene
    {
    public:

        Scene() = default;
        virtual ~Scene() = default;

        virtual void OnInit() = 0;
        virtual void OnEnter() = 0;

        virtual void Update() = 0;
        virtual void Draw() = 0;

        virtual void OnExit() = 0;
    };
}