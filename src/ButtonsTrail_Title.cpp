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

    this->gameStats.titleSel = maxLevel > 0 ? TitleScreenMode::LevelSelect : TitleScreenMode::NewGame;
    this->gameStats.maxLevel = maxLevel;
    this->gameStats.level = curlevel;
    
    this->gameState = GameState::Title;
    this->playTheme();

}   


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void Game::title() {

    updateAndRenderParticles();

    if (PC::frameCount % 32 == 0) launchParticles(random(32, 188), random(16, 120), PC::frameCount % 64 == 0);


    // Handle player actions ..

    if (PC::buttons.pressed(BTN_LEFT) && this->gameStats.titleSel != TitleScreenMode::NewGame) { 

        switch (this->gameStats.titleSel) {
            
            case TitleScreenMode::SoundEffects:
                if (this->gameStats.maxLevel > 0) { 
                    this->gameStats.titleSel = TitleScreenMode::LevelSelect;
                }
                else {
                    this->gameStats.titleSel = TitleScreenMode::NewGame;
                }
                break;

            case TitleScreenMode::LevelSelect:
                this->gameStats.titleSel--;
                break;

            default: break;

        }

    }         

    if (PC::buttons.pressed(BTN_RIGHT)) {

        switch (this->gameStats.titleSel) {
            
            case TitleScreenMode::NewGame:
                if (this->gameStats.maxLevel > 0) { 
                    this->gameStats.titleSel = TitleScreenMode::LevelSelect;
                }
                else {
                    this->gameStats.titleSel = TitleScreenMode::SoundEffects;
                }
                break;

            case TitleScreenMode::LevelSelect:
                this->gameStats.titleSel++;
                break;

            default: break;

        }

    }         

    if (this->gameStats.titleSel == TitleScreenMode::SoundEffects) {

        if (PC::buttons.pressed(BTN_UP)) {

            this->cookie->sfx--;
            this->cookie->saveCookie();

            if (this->cookie->sfx != SoundEffects::Both && this->cookie->sfx != SoundEffects::Music) {

                this->muteTheme();
                
            }
            else {

                this->playTheme();

            }

        }

        if (PC::buttons.pressed(BTN_DOWN)) {

            this->cookie->sfx++;
            this->cookie->saveCookie();

            if (this->cookie->sfx != SoundEffects::Both && this->cookie->sfx != SoundEffects::Music) {

                this->muteTheme();
                
            }
            else {

                this->playTheme();
                
            }
            
        }

    }


    if (PC::buttons.pressed(BTN_A)) { 

        if (gameStats.titleSel == TitleScreenMode::NewGame) { 
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

    PD::drawBitmap(14, 33, Images::Title);
    PD::drawBitmap(49, 108, Images::Title_New);

    if (PC::frameCount % 128 < 2) {

        PD::drawBitmap(93, 72, Images::Eyes);

    }


    if (this->gameStats.maxLevel > 0) {
     
        PD::drawBitmap(129, 108, Images::Title_Continue);

    }

    switch (this->cookie->sfx) {

        case SoundEffects::Music:
            PD::drawBitmap(96, 125, this->gameStats.titleSel == TitleScreenMode::SoundEffects ? Images::Sound_Music_White: Images::Sound_Music_Grey);
            break;

        case SoundEffects::SFX:
            PD::drawBitmap(96, 125, this->gameStats.titleSel == TitleScreenMode::SoundEffects ? Images::Sound_SFX_White: Images::Sound_SFX_Grey);
            break;

        case SoundEffects::Both:
            PD::drawBitmap(96, 125, this->gameStats.titleSel == TitleScreenMode::SoundEffects? Images::Sound_Both_White: Images::Sound_Both_Grey);
            break;

        default:
            PD::drawBitmap(96, 125, this->gameStats.titleSel == TitleScreenMode::SoundEffects ? Images::Sound_None_White: Images::Sound_None_Grey);
            break;

    }

    uint8_t frame = (PC::frameCount % 60) / 12;

    switch (this->gameStats.titleSel) {

        case TitleScreenMode::NewGame:
            PD::drawBitmap(36, 108, Images::Skulls_Title[frame]);
            break;

        case TitleScreenMode::LevelSelect:
            PD::drawBitmap(116, 108, Images::Skulls_Title[frame]);
            break;
            
    }

    int8_t spacing[] = { 0, 1, 0, -1, -2, 0, 1, 2, 1, 3, 0, 1, -2, 1 };

    for (int16_t x = -18, i = 0; x < 220;) {

        PD::drawBitmap(x, 142, Images::Fire[((PC::frameCount + (spacing[i] * 6)) % 60) / 5]);
        x = x + 23 + spacing[i];
        i++;

    }

}
