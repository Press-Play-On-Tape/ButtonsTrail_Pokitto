#pragma once

#include "../utils/Utils.h"

struct SplashScreenVariables {

    uint8_t counter = 0;
    uint8_t buttonCounter = 0;

};

struct CharacterVariables {

    uint16_t armCount = 0;
    Direction armDirection = Direction::Down;

};

struct GameStats {

    public: 

        GameStats() { };

        TitleScreenMode titleSel = TitleScreenMode::NewGame;
        GameMode mode= GameMode::NoOther;
        
        uint8_t level = 0;
        uint8_t maxLevel = 0;
        
        int16_t xOffset = 0;
        uint8_t yOffset = 0;
        uint16_t moves = 0;
        uint8_t minimumMoves = 0;
        uint8_t instruction = 0;
        uint8_t exit = 0;

        bool endOfGame = false;
        uint8_t endOfGameCount = 0;
        uint8_t stars = 0;
        uint8_t puffOfSmoke = 0;

        void reset() {
        }

};


struct LevelSelectVars {

    public: 

        LevelSelectVars() { };

        uint8_t cursor = 0;
        uint8_t cursorFlashTop = 0;
        uint8_t cursorFlashBottom = 0;
        uint8_t topRow = 0;

};