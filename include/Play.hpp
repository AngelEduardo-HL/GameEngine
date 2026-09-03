#ifndef SKIBIDI_PLAY_HPP
#define SKIBIDI_PLAY_HPP

#include "Scene.hpp"
#include "EventBus.hpp"
#include "player.hpp"
#include "ship.h"
#include "entityManager.h"
#include "bullet.h"
#include "resources_manager.h"
#define MAX_BULLETS 10

namespace skibidi
{
    class Play :
        public Scene,
        public EventListener
    {
    private:

        bool eventsBound = false;

    public:

        Play() = default;
        ~Play() override = default;


        void OnInit() override;
        void OnEnter() override;

        void Update() override;
        void Draw() override;

        void OnExit() override;


        void onEvent(
            EventData data
        ) override;

        void Shoot();


        // =========================
        // PLAYER Y ENTIDADES
        // =========================

        Player player;

        EntityManager entityMgr;

        Ship* ship;
        Ship* ship2;
        Bullet* bullet;


        // =========================
        // EVENTOS
        // =========================

        int eventId_01 = 0;
        int eventId_02 = 0;

        int playerScore = 0;
        int grabCoinEvId = 0;


        // =========================
        // RESOURCE MANAGER
        // =========================

        ResourcesManager& assets =
            ResourcesManager::get();

        Font font = {};

        Sound sound = {};

        Music bg_music = {};

        Texture2D textureBG = {};
    };
}

#endif