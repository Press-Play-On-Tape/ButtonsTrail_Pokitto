#include "ButtonsTrail.h"
#include "images/images.h"
#include "utils/Utils.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;

#define LEVELS_TO_SHOW 6


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void Game::levelSelect_Init() {

    this->gameState = GameState::LevelSelect;

    levelSelectVars.cursor = this->cookie->levelCurrent;
    this->gameStats.maxLevel = this->cookie->levelMax;
    
    if (this->gameStats.maxLevel <= LEVELS_TO_SHOW / 2)                                 { levelSelectVars.topRow = 0; }
    else if (levelSelectVars.cursor <= LEVELS_TO_SHOW / 2)                              { levelSelectVars.topRow = 0; }
    else if (levelSelectVars.cursor > Puzzles::Count - (LEVELS_TO_SHOW / 2))            { levelSelectVars.topRow = Puzzles::Count - LEVELS_TO_SHOW; }
    else                                                                                { levelSelectVars.topRow = levelSelectVars.cursor - 3; }
}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void Game::levelSelect() { 

    PD::drawBitmap(38, 7, Images::LevelSelect);
    PD::setColor(2);


    // Draw upper border ..

    for (uint8_t x = 0; x < 220; x = x + 28) {
        PD::drawBitmap(x, 32, Images::Divider);
    }


    // Draw character ..

    if (PC::frameCount % 16 == 0) {

        switch (this->characterVariables.armDirection) {

            case Direction::Down:
                this->characterVariables.armCount = this->characterVariables.armCount + 1;
                if (this->characterVariables.armCount == 2) this->characterVariables.armDirection = Direction::Up;
                break;

            case Direction::Up:
                this->characterVariables.armCount = this->characterVariables.armCount - 1;
                if (this->characterVariables.armCount == 0) this->characterVariables.armDirection = Direction::Down;
                break;
                
        } 
    }

    PD::drawBitmap(145, 35, Images::Body);
    PD::drawBitmap(141, 95 + this->characterVariables.armCount, Images::Arm_Left);
    PD::drawBitmap(180, 95 + this->characterVariables.armCount, Images::Arm_Right);
    
    if (PC::frameCount % 128 < 2) {

        PD::drawBitmap(161, 74, Images::EyesClosed);

    }


    // Draw lower border ..

    for (uint8_t x = 0; x < 220; x = x + 28) {
        PD::drawBitmap(x, 150, Images::Divider);
    }



    // Handle player input ..

    if (levelSelectVars.cursorFlashTop > 0)     levelSelectVars.cursorFlashTop--;
    if (levelSelectVars.cursorFlashBottom > 0)  levelSelectVars.cursorFlashBottom--;

    if (PC::buttons.pressed(BTN_A)) {

        this->gameStats.level = levelSelectVars.cursor;
        this->gameStats.moves = 0;
        this->cookie->levelCurrent = this->gameStats.level;
        this->cookie->saveCookie();
        this->gameState = GameState::Game_Init; 

    }

    if (PC::buttons.pressed(BTN_B)) {

        this->gameState = GameState::Title_Init; 

    }

    if (PC::buttons.pressed(BTN_UP) && levelSelectVars.cursor > 0) {

        levelSelectVars.cursor--;
        levelSelectVars.cursorFlashTop = 4;

        if (this->gameStats.maxLevel <= LEVELS_TO_SHOW / 2)                                 { levelSelectVars.topRow = 0; }
        else if (levelSelectVars.cursor <= LEVELS_TO_SHOW / 2)                              { levelSelectVars.topRow = 0; }
        else if (levelSelectVars.cursor > Puzzles::Count - (LEVELS_TO_SHOW / 2))            { levelSelectVars.topRow = Puzzles::Count - LEVELS_TO_SHOW; }
        else                                                                                { levelSelectVars.topRow = levelSelectVars.cursor - 3; }

    }

    if (PC::buttons.pressed(BTN_DOWN) && levelSelectVars.cursor < this->gameStats.maxLevel) {

        levelSelectVars.cursor++;
        levelSelectVars.cursorFlashBottom = 4;

        if (this->gameStats.maxLevel <= LEVELS_TO_SHOW / 2)                                 { levelSelectVars.topRow = 0; }
        else if (levelSelectVars.cursor <= LEVELS_TO_SHOW / 2)                              { levelSelectVars.topRow = 0; }
        else if (levelSelectVars.cursor > Puzzles::Count - (LEVELS_TO_SHOW / 2))            { levelSelectVars.topRow = Puzzles::Count - LEVELS_TO_SHOW; }
        else                                                                                { levelSelectVars.topRow = levelSelectVars.cursor - 3; }

    }


    // Render rows ..

    uint8_t y = 62;

    for (uint8_t i = levelSelectVars.topRow; i <= (levelSelectVars.topRow + LEVELS_TO_SHOW > Puzzles::Count ? Puzzles::Count : levelSelectVars.topRow + LEVELS_TO_SHOW); i++) {

        uint8_t enabled = i <= gameStats.maxLevel;

        if (enabled) {
            PD::drawBitmap(31, y, Images::Level);
        }
        else {
            PD::drawBitmap(31, y, Images::Level_Disabled);
        }

        {
            uint8_t digits[2] = {};
            uint8_t x = 74;

            extractDigits(digits, i);

            for (uint8_t i = 0; i < 2; ++i) {

                if (digits[i] == 1) x = x - 3;

            }

            for (uint8_t i = 0; i < 2; ++i) {

                if (enabled) {
                    PD::drawBitmap(x, y, Images::Numbers[digits[i]]);
                }
                else {
                    PD::drawBitmap(x, y, Images::Numbers_Disabled[digits[i]]);
                }

                x = x - (digits[i] == 1 ? 5 : 8);
            }

        }

        uint8_t stars = this->cookie->levelRating[i];

        if (enabled) {
            PD::drawBitmap(88, y - 1, (stars > 0 ? Images::Star_Filled : Images::Star_Hollow));
            PD::drawBitmap(100, y - 1, (stars > 1 ? Images::Star_Filled : Images::Star_Hollow));
            PD::drawBitmap(112, y - 1, (stars > 2 ? Images::Star_Filled : Images::Star_Hollow));
        }
        else {
            PD::drawBitmap(88, y - 1, (stars > 0 ? Images::Star_Filled_Disabled : Images::Star_Hollow_Disabled));
            PD::drawBitmap(100, y - 1, (stars > 1 ? Images::Star_Filled_Disabled : Images::Star_Hollow_Disabled));
            PD::drawBitmap(112, y - 1, (stars > 2 ? Images::Star_Filled_Disabled : Images::Star_Hollow_Disabled));
        }

        if (i == levelSelectVars.cursor) {
            PD::drawBitmap(4, y - 3, Images::Pointer);
        }

        y = y + 12;

    }


}
