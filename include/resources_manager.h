#pragma once

#include <unordered_map>
#include <string>

#include "raylib.h"

namespace skibidi
{
    class ResourcesManager
    {
    public:

        static ResourcesManager& get()
        {
            static ResourcesManager rm;

            return rm;
        }


        // ==========================================
        // TEXTURAS
        // ==========================================

        Texture2D& getTexture(
            const std::string& file
        )
        {
            std::string fullPath =
                texturePath + file;


            // Revisar si ya fue cargada
            auto it =
                textures.find(fullPath);


            if (it != textures.end())
            {
                return it->second;
            }


            // Revisar si existe
            if (!FileExists(fullPath.c_str()))
            {
                std::string msg =
                    "No se encontro textura: "
                    + fullPath;

                TraceLog(
                    LOG_WARNING,
                    "%s",
                    msg.c_str()
                );


                // Creamos entrada vacia
                textures[fullPath] = {};

                return textures[fullPath];
            }


            // Cargar textura
            textures[fullPath] =
                LoadTexture(
                    fullPath.c_str()
                );


            return textures[fullPath];
        }


        // ==========================================
        // FUENTES
        // ==========================================

        Font& getFont(
            const std::string& file
        )
        {
            std::string fullPath =
                fontPath + file;


            auto it =
                fonts.find(fullPath);


            if (it != fonts.end())
            {
                return it->second;
            }


            if (!FileExists(fullPath.c_str()))
            {
                std::string msg =
                    "No se encontro fuente: "
                    + fullPath;

                TraceLog(
                    LOG_WARNING,
                    "%s",
                    msg.c_str()
                );


                fonts[fullPath] = {};

                return fonts[fullPath];
            }


            fonts[fullPath] =
                LoadFontEx(
                    fullPath.c_str(),
                    16,
                    nullptr,
                    0
                );


            return fonts[fullPath];
        }


        // ==========================================
        // SONIDOS
        // ==========================================

        Sound& getSound(
            const std::string& file
        )
        {
            std::string fullPath =
                soundPath + file;


            auto it =
                sounds.find(fullPath);


            if (it != sounds.end())
            {
                return it->second;
            }


            if (!FileExists(fullPath.c_str()))
            {
                std::string msg =
                    "No se encontro sonido: "
                    + fullPath;

                TraceLog(
                    LOG_WARNING,
                    "%s",
                    msg.c_str()
                );


                sounds[fullPath] = {};

                return sounds[fullPath];
            }


            sounds[fullPath] =
                LoadSound(
                    fullPath.c_str()
                );


            return sounds[fullPath];
        }


        // ==========================================
        // MUSICA
        // ==========================================

        Music& getMusic(
            const std::string& file
        )
        {
            std::string fullPath =
                musicPath + file;


            auto it =
                music.find(fullPath);


            if (it != music.end())
            {
                return it->second;
            }


            if (!FileExists(fullPath.c_str()))
            {
                std::string msg =
                    "No se encontro musica: "
                    + fullPath;

                TraceLog(
                    LOG_WARNING,
                    "%s",
                    msg.c_str()
                );


                music[fullPath] = {};

                return music[fullPath];
            }


            music[fullPath] =
                LoadMusicStream(
                    fullPath.c_str()
                );


            return music[fullPath];
        }


    private:

        ResourcesManager() = default;


        // TEXTURAS
        std::unordered_map<
            std::string,
            Texture2D
        > textures;

        std::string texturePath =
            "textures/";


        // FUENTES
        std::unordered_map<
            std::string,
            Font
        > fonts;

        std::string fontPath =
            "fonts/";


        // SONIDOS
        std::unordered_map<
            std::string,
            Sound
        > sounds;

        std::string soundPath =
            "sounds/";


        // MUSICA
        std::unordered_map<
            std::string,
            Music
        > music;

        std::string musicPath =
            "music/";
    };
}