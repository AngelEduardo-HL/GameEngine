#ifndef SKIBIDI_PLAY_HPP
#define SKIBIDI_PLAY_HPP

#include "Scene.hpp"
#include "EventBus.hpp"

#include "player.hpp"
#include "ship.h"
#include "entityManager.h"
#include "game_manager.h"
#include "bullet.h"
#include "enemy.h"
#include "power_up.h"

#include "score.h"
#include "resources_manager.h"

namespace skibidi
{
    class Play :
        public Scene,
        public EventListener
    {
    private:
        bool eventsBound = false;

        static constexpr int MAX_BULLETS = 10;
        static constexpr int MAX_ENEMIES = 5;

        const float ENEMY_SPAWN_INTERVAL = 2.0f;

        const float DOUBLE_SHOT_DURATION = 8.0f;
        const int POWER_UP_DROP_CHANCE = 30;

        Bullet bullets[MAX_BULLETS];
        Enemy enemies[MAX_ENEMIES];

        PowerUp powerUp;

        float doubleShotTimer = 0.0f;

    public:
        Play() = default;
        ~Play() override = default;

        void OnInit() override;
        void OnEnter() override;
        void Update() override;
        void Draw() override;
        void OnExit() override;

        void SpawnEnemy();
        void SpawnPowerUp(Vector2 position);

        void Shoot();
        bool FireBullet(Vector2 position);

        void CheckCollisions();
        void ResetGame();

        void onEvent(EventData data) override;

        Player player;
        EntityManager entityMgr;

        GameManager gameManager;

        Vector2 shipOrigin = { 0.0f, 0.0f };

        Ship* ship = nullptr;

        Score* score = nullptr;

        float spawnTimer = 0.0f;

        int eventId_01 = 0;
        int eventId_02 = 0;
        int playerScore = 0;
        int grabCoinEvId = 0;

        ResourcesManager& assets = ResourcesManager::get();

        Font font = {};
        Sound sound = {};
        Music bg_music = {};
        Texture2D textureBG = {};
    };
}

#endif