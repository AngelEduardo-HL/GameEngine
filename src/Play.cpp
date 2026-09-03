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

            // Crear entidades
            ship = new Ship();
            ship2 = new Ship();
            bullet = new Bullet();

            // Posiciones
            ship->setPosition(
                10,
                20
            );

            ship2->setPosition(
                150,
                225
            );

            bullet->setPosition(
                400,
                300
            );

            // Agregar al Entity Manager
            entityMgr.add(ship);
            entityMgr.add(ship2);
            entityMgr.add(bullet);

            // =========================================
            // RESOURCE MANAGER
            // =========================================

            // FUENTE
            font = assets.getFont("SpaceFont3.ttf");

            // SONIDO
            sound = assets.getSound("Pew.wav");

            // MUSICA
            bg_music = assets.getMusic("SpaceMusic.mp3");

            // TEXTURA DE FONDO
            textureBG = assets.getTexture("SpaceBG.png");

            eventsBound = true;
        }
    }

    void Play::OnEnter()
    {
        TraceLog(LOG_INFO,"Entrando a Play");

        // Iniciar musica
        PlayMusicStream(bg_music);
    }

    void Play::Update()
    {
        // =========================================
        // MUSICA
        // =========================================

        UpdateMusicStream(bg_music);

        // =========================================
        // ENTIDADES
        // =========================================

        entityMgr.update();

        // =========================================
        // SONIDO CON CLICK IZQUIERDO
        // =========================================

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            TraceLog(LOG_INFO,"Mouse Left Button Pressed");

            EventData data;

            data.type = "onclick";

            EventBus::get().fire("onclick",data);

            // Reproducir sonido
            PlaySound(sound);
        }

        // =========================================
        // EVENTOS DEL PLAYER
        // =========================================

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

        // =========================================
        // REGRESAR AL MENU
        // =========================================

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            SceneManager::get().changeScene("menu");
        }
    }

    void Play::Draw()
    {
        // =========================================
        // FONDO
        // =========================================

        DrawTextureEx(
            textureBG,
            { 0.0f, 0.0f },
            0.0f,
            1.0f,
            WHITE);

        // =========================================
        // ENTIDADES
        // =========================================

        entityMgr.draw();

        // =========================================
        // TEXTO CON FUENTE
        // =========================================

        DrawTextEx(
            font,
            "Space Game",
            { 100.0f, 100.0f },
            40.0f,
            0.0f,
            WHITE);

        DrawText(
            "CLICK IZQUIERDO = Sonido",
            20,
            500,
            20,
            WHITE);

        DrawText(
            "C = Grab Coin | E = Enemy Hit | P = Player Hit",
            20,
            530,
            18,
            WHITE);

        DrawText(
            "BACKSPACE = Menu",
            20,
            560,
            18,
            WHITE);
    }


    void Play::OnExit()
    {
        TraceLog(LOG_INFO,"Saliendo de Play");

        // Detener musica al salir de Play
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