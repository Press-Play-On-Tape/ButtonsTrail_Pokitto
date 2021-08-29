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
        Player other;
        FallingTile fallingTiles[Constants::FallingTilesCount];
        Arrow arrows[3];

        Tiles board[Constants::BoardHeight][Constants::BoardWidth];
        Particle particles[Constants::ParticlesMax];

        GameCookie *cookie;
        File mainThemeFile;


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

        void removeTile(Player &character);
        void initGame(uint8_t level);
        bool endOfGame();
        void launchParticles(int16_t x, int16_t y, bool firstHalf);
        void updateAndRenderParticles();
        void renderBoard();
        void renderHUD();

        void playTheme();
        void muteTheme();
        void playSoundEffect(SoundEffect soundEffect);
        void printBoard();
        void moveOther();
        bool canMoveToTile(uint8_t x, uint8_t y);

};

