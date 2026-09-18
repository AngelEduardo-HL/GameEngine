#include "Play.hpp"

#include "raylib.h"
#include "json.hpp"
#include "scene_manager.hpp"
#include <fstream>

using json = nlohmann::json;

namespace skibidi
{
    void Play::OnInit()
    {
        // Solo crear objetos y registrar eventos una vez.
        if (!eventsBound)
        {
            listen("grab_coin");
            listen("enemy_hit");
            listen("player_hit");

            ship = new Ship();

            // EntityManager controla solamente la nave.
            entityMgr.add(ship);

            score = new Score();

            gameManager.init();

            font = assets.getFont("SpaceFont3.ttf");
            sound = assets.getSound("Pew.wav");
            bg_music = assets.getMusic("SpaceMusic.mp3");
            textureBG = assets.getTexture("SpaceBG.png");

			char* j = LoadFileText("json/PP.json");

			json data = json::parse(j);

            if (data.is_array() && data.size() > 1) {
				std::string name = data[0]["name"];
				float x = data[0]["x"];
				float y = data[0]["y"];
            }

            for (const auto& d : data) {
                std::string name = d["name"];
                float x = d["x"];
                float y = d["y"];
            }

			json item;

            eventsBound = true;
        }

        // OnInit se ejecuta cada vez que volvemos a Play.
        ResetGame();
    }


    void Play::ResetGame()
    {
        shipOrigin =
        {
            GetScreenWidth() / 2.0f,
            GetScreenHeight() - 100.0f
        };

        ship->setActive(true);
        ship->setPosition(shipOrigin);

        score->reset();
        gameManager.reset();

        spawnTimer = 0.0f;
        doubleShotTimer = 0.0f;

        powerUp.setActive(false);

        for (int i = 0; i < MAX_BULLETS; ++i)
        {
            bullets[i].setActive(false);
        }

        for (int i = 0; i < MAX_ENEMIES; ++i)
        {
            enemies[i].setActive(false);
        }

        TraceLog(LOG_INFO, "Nueva partida iniciada");
    }


    void Play::OnEnter()
    {
        TraceLog(LOG_INFO, "Entrando a Play");

        PlayMusicStream(bg_music);
    }


    void Play::Update()
    {
        UpdateMusicStream(bg_music);

        // NAVE
        entityMgr.update();

        // SPAWN ENEMIGOS
        spawnTimer += GetFrameTime();

        if (spawnTimer >= ENEMY_SPAWN_INTERVAL)
        {
            spawnTimer = 0.0f;
            SpawnEnemy();
        }

        // BALAS
        for (int i = 0; i < MAX_BULLETS; ++i)
        {
            if (bullets[i].isActive())
            {
                bullets[i].update();
            }
        }

        // ENEMIGOS
        for (int i = 0; i < MAX_ENEMIES; ++i)
        {
            if (enemies[i].isActive())
            {
                enemies[i].update();
            }
        }

        // POWER-UP
        if (powerUp.isActive())
        {
            powerUp.update();
        }

        // DURACION DOUBLE SHOT
        if (doubleShotTimer > 0.0f)
        {
            doubleShotTimer -= GetFrameTime();

            if (doubleShotTimer < 0.0f)
            {
                doubleShotTimer = 0.0f;
            }
        }

        CheckCollisions();

        // DISPARO
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            Shoot();
            PlaySound(sound);

            EventData data;
            data.type = "onclick";

            EventBus::get().fire("onclick", data);
        }

        // EVENTOS DE PRUEBA QUE YA TENIAS
        if (IsKeyPressed(KEY_C))
        {
            player.GrabCoin();
        }

        if (IsKeyPressed(KEY_E))
        {
            player.EnemyHit();
        }

        if (IsKeyPressed(KEY_P))
        {
            player.PlayerHit();
        }

        // REGRESO AL MENU
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            SceneManager::get().changeScene("menu");
        }
    }


    bool Play::FireBullet(Vector2 position)
    {
        for (int i = 0; i < MAX_BULLETS; ++i)
        {
            if (!bullets[i].isActive())
            {
                bullets[i].fire(position);

                return true;
            }
        }

        return false;
    }


    void Play::Shoot()
    {
        if (ship == nullptr)
        {
            return;
        }

        Vector2 muzzle = ship->getMuzzlePosition();

        // POWER-UP ACTIVO
        if (doubleShotTimer > 0.0f)
        {
            bool leftShot = FireBullet({muzzle.x - 18.0f,muzzle.y});
            bool rightShot = FireBullet({muzzle.x + 18.0f,muzzle.y});

            if (!leftShot && !rightShot)
            {
                TraceLog(LOG_WARNING, "Bullet Pool lleno");
            }

            return;
        }

        // DISPARO NORMAL
        if (!FireBullet(muzzle))
        {
            TraceLog(LOG_WARNING, "Bullet Pool lleno");
        }
    }


    void Play::CheckCollisions()
    {
        // =========================================
        // BALAS VS ENEMIGOS
        // =========================================

        for (int i = 0; i < MAX_BULLETS; ++i)
        {
            if (!bullets[i].isActive())
            {
                continue;
            }

            for (int j = 0; j < MAX_ENEMIES; ++j)
            {
                if (!enemies[j].isActive())
                {
                    continue;
                }

                if (bullets[i].collidesWith(enemies[j]))
                {
                    Vector2 enemyPosition =
                        enemies[j].getPosition();

                    bullets[i].setActive(false);
                    enemies[j].setActive(false);

                    score->addPoint();

                    // 30% de probabilidad de Power-Up.
                    if (!powerUp.isActive() && GetRandomValue(1, 100) <= POWER_UP_DROP_CHANCE)
                    {
                        SpawnPowerUp(enemyPosition);
                    }

                    EventData data;
                    data.type = "enemy_kill";

                    EventBus::get().fire("enemy_kill", data);

                    // Esta bala ya impacto.
                    break;
                }
            }
        }


        // =========================================
        // ENEMIGOS VS JUGADOR
        // =========================================

        for (int j = 0; j < MAX_ENEMIES; ++j)
        {
            if (!enemies[j].isActive())
            {
                continue;
            }

            if (ship->collidesWith(enemies[j]))
            {
                enemies[j].setActive(false);

                ship->setPosition(shipOrigin);

                score->shipKilled();

                EventData data;
                data.type = "player_kill";

                EventBus::get().fire("player_kill", data);
            }
        }


        // =========================================
        // POWER-UP VS JUGADOR
        // =========================================

        if (powerUp.isActive() &&ship-> collidesWith(powerUp))
        {
            powerUp.setActive(false);

            doubleShotTimer =
                DOUBLE_SHOT_DURATION;

            TraceLog(LOG_INFO, "DOUBLE SHOT ACTIVADO");
        }
    }

    void Play::SpawnEnemy()
    {
        for (int i = 0; i < MAX_ENEMIES; ++i)
        {
            if (!enemies[i].isActive())
            {
                float x = static_cast<float>(GetRandomValue(70, GetScreenWidth() - 70));

                enemies[i].setPosition(x, -50.0f);
                enemies[i].setActive(true);

                TraceLog(LOG_INFO,"Enemy %i activado", i);

                return;
            }
        }

        TraceLog(LOG_WARNING,"Enemy Pool lleno");
    }

    void Play::SpawnPowerUp(Vector2 position)
    {
        powerUp.spawn(position);

        TraceLog(LOG_INFO,"PowerUp Double Shot generado");
    }

    void Play::Draw()
    {
        // FONDO
        if (textureBG.id != 0)
        {
            DrawTextureEx(textureBG, { 0.0f, 0.0f }, 0.0f, 1.0f, WHITE);
        }
        // JUGADOR
        entityMgr.draw();
        // ENEMIGOS
        for (int i = 0; i < MAX_ENEMIES; ++i)
        {
            if (enemies[i].isActive())
            {
                enemies[i].draw();
            }
        }

        // BALAS
        for (int i = 0; i < MAX_BULLETS; ++i)
        {
            if (bullets[i].isActive())
            {
                bullets[i].draw();
            }
        }

        // POWER-UP
        if (powerUp.isActive())
        {
            powerUp.draw();
        }
        // UN SOLO HUD
        score->draw();
        // POWER-UP ACTIVO
        if (doubleShotTimer > 0.0f)
        {
            DrawTextEx(font, TextFormat("DOUBLE SHOT: %.1f", doubleShotTimer), { 20.0f, 85.0f }, 20.0f, 0.0f, GOLD);
        }

        DrawTextEx(font, "Space Game", { 100.0f, 100.0f }, 40.0f, 0.0f, WHITE);
        DrawText("CLICK IZQUIERDO = DISPARAR", 20, 500, 20, WHITE);
        DrawText("BACKSPACE = Menu", 20, 560, 18, WHITE);
    }


    void Play::OnExit()
    {
        TraceLog(LOG_INFO,"Saliendo de Play");

        StopMusicStream(bg_music);
    }

    void Play::onEvent(EventData data)
    {
        if (data.type == "grab_coin")
        {
            playerScore++;
            TraceLog(LOG_INFO, "Evento: grab_coin");
        }

        else if (data.type == "enemy_hit")
        {
            TraceLog(LOG_INFO, "Evento: enemy_hit");
        }

        else if (data.type == "player_hit")
        {
            TraceLog(LOG_INFO, "Evento: player_hit");
        }
    }
}