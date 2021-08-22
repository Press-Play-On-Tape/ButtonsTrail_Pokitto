#pragma once

#include "Pokitto.h"
#include <LibAudio>
#include <LibSchedule>
#include "entities/Entities.h"
#include "images/Images.h"
#include "utils/Enums.h"
#include "utils/GameCookie.h"
#include "puzzles/Puzzles.h"
#include "sounds/Sounds.h"

using PC=Pokitto::Core;
using PD=Pokitto::Display;
using PB=Pokitto::Buttons;


class Game {

    private:

        SplashScreenVariables splashScreenVariables;
        CharacterVariables characterVariables;
        LevelSelectVars levelSelectVars;
        GameState gameState = GameState::Splash;
        GameStats gameStats;
        Player player;
        FallingTile fallingTiles[Constants::FallingTilesCount];
        Arrow arrows[3];

        uint8_t board[Constants::BoardHeight][Constants::BoardWidth];
        Particle particles[Constants::ParticlesMax];

        GameCookie *cookie;


    public:

        void setup(GameCookie *cookie);
        void loop();

    private:

        void splashScreen();
        void game_Init();
        void game();
        void instructions_Init();
        void instructions();
        void levelSelect_Init();
        void levelSelect();
        void title_Init();
        void title();

        void removeTile();
        void initGame(uint8_t level);
        bool endOfGame();
        void launchParticles(int16_t x, int16_t y, bool firstHalf);
        void updateAndRenderParticles();
        void renderBoard();
        void renderHUD();

        void playTheme(uint8_t trackNumber);
        void muteTheme();
        void playSoundEffect(SoundEffect soundEffect);

};

