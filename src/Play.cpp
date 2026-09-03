#include "Play.hpp"

#include "raylib.h"
#include "scene_manager.hpp"


namespace skibidi
{
    void Play::OnInit()
    {
        if (!eventsBound)
        {
            listen("grab_coin");
            listen("enemy_hit");
            listen("player_hit");

            ship = new Ship();

            ship->setPosition(300.0f,500.0f);
			//Posicion aleatoria de enemigos
			enemies->setPosition(GetRandomValue(50, 750), GetRandomValue(-100, -50));

            entityMgr.add(ship);
			entityMgr.add(enemies);

            font = assets.getFont("SpaceFont3.ttf");

            sound = assets.getSound("Pew.wav");
            bg_music = assets.getMusic("SpaceMusic.mp3");

            textureBG =assets.getTexture("SpaceBG.png");
            eventsBound = true;
        }
    }

    void Play::OnEnter()
    {
        TraceLog(LOG_INFO,"Entrando a Play");
        PlayMusicStream(bg_music);
    }

    void Play::Update()
    {

        UpdateMusicStream(bg_music);
        entityMgr.update();

        for (int i = 0;i < MAX_BULLETS;++i)
        {
            if (bullets[i].isActive())
            {
                bullets[i].update();
            }
        }

        for (int i = 0;i < MAX_ENEMIES;++i)
        {
            if (enemies[i].isActive())
            {
                enemies[i].update();
            }
		}

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            TraceLog(LOG_INFO,"Disparo");

            Shoot();
            PlaySound(sound);

            EventData data;
            data.type ="onclick";
            EventBus::get().fire("onclick",data);
        }

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

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            SceneManager::get().changeScene("menu");
        }
    }

    void Play::Draw()
    {

        if (textureBG.id != 0)
        {
            DrawTextureEx(textureBG,{0.0f,0.0f},0.0f,1.0f,WHITE);
        }

        entityMgr.draw();

        for (int i = 0;i < MAX_BULLETS;++i)
        {
            if (bullets[i].isActive())
            {
                bullets[i].draw();
            }
        }

        DrawTextEx(font,"Space Game",{100.0f,100.0f},40.0f,0.0f,WHITE);

        DrawText("CLICK IZQUIERDO = DISPARAR",20,500,20,WHITE);

        DrawText("BACKSPACE = Menu",20,560,18,WHITE);
    }

    void Play::Shoot()
    {
        if (ship == nullptr)
        {
            return;
        }

        for (int i = 0;i < MAX_BULLETS;++i)
        {
            if (!bullets[i].isActive())
            {
                bullets[i].fire(ship->getMuzzlePosition());
                TraceLog(LOG_INFO,"Bullet %i activada",i);

                return;
            }
        }
        TraceLog(LOG_WARNING,"Bullet Pool lleno");

        //Enemy
        for (int i = 0;i < MAX_ENEMIES;++i)
        {
            if (!enemies[i].isActive())
            {
                enemies[i].setPosition(GetRandomValue(50, 750), GetRandomValue(-100, -50));
                TraceLog(LOG_INFO,"Enemy %i activado",i);
                return;
            }
		}

    }

    void Play::OnExit()
    {
        TraceLog(LOG_INFO,"Saliendo de Play");

        StopMusicStream(bg_music);
    }

    void Play::onEvent(EventData data)
    {
        if (data.type =="grab_coin")
        {
            playerScore++;
            TraceLog(LOG_INFO,"Evento: grab_coin");
        }

        else if (data.type =="enemy_hit")
        {
            TraceLog(LOG_INFO,"Evento: enemy_hit");
        }

        else if (data.type =="player_hit")
        {
            TraceLog(LOG_INFO,"Evento: player_hit");
        }
    }
}