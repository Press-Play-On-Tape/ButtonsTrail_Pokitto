#include "ButtonsTrail.h"
#include "images/images.h"
#include "utils/Utils.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void Game::title_Init() {

    uint8_t maxLevel = this->cookie->levelMax;
    uint8_t curlevel = this->cookie->levelCurrent;

    this->gameStats.titleSel = maxLevel > 0 ? 1 : 0;
    this->gameStats.maxLevel = maxLevel;
    this->gameStats.level = curlevel;
    
    this->gameState = GameState::Title;
    
}   


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void Game::title() {


    // Handle player actions ..

    if (PC::buttons.pressed(BTN_LEFT)) { 

        this->gameStats.titleSel = 0;

    }         

    if (PC::buttons.pressed(BTN_RIGHT) && this->gameStats.maxLevel > 0) { 

        this->gameStats.titleSel = 1;

    }         

    if (PC::buttons.pressed(BTN_A)) { 

        if (gameStats.titleSel == 0) { 
            this->gameStats.level = 0;
            this->gameStats.instruction = 0;
            this->gameState = GameState::Instructions_Init;
            this->cookie->levelCurrent = this->gameStats.level;
            this->cookie->saveCookie();
        }
        else {
            this->gameState = GameState::LevelSelect_Init;
        }

    }         


    // Render page ..

    PD::drawBitmap(14, 38, Images::Title);
    PD::drawBitmap(49, 113, Images::Title_New);

    if (PC::frameCount % 128 < 2) {

        PD::drawBitmap(93, 77, Images::Eyes);

    }


    if (this->gameStats.maxLevel > 0) {
     
        PD::drawBitmap(129, 113, Images::Title_Continue);

    }

    uint8_t frame = (PC::frameCount % 60) / 12;
    PD::drawBitmap(36 + (gameStats.titleSel * 79), 113, Images::Skulls_Title[frame]);

}
