#include "ButtonsTrail.h"
#include "images/images.h"
#include "utils/Utils.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void Game::congratulations_Init() {

    this->gameState = GameState::Congratulations;
    this->characterVariables.armCount = 0;
    this->playSoundEffect(SoundEffect::Tone_09);

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void Game::congratulations() { 

    int8_t spacing[] = { 0, 1, 0, -1, -2, 0, 1, 2, 1, 3, 0, 1, -2, 1 };

    PD::setColor(2);

    updateAndRenderParticles();

    switch (this->characterVariables.armCount) {

        case 0 ... 29:
            if (PC::frameCount % 3 == 0) {
                this->characterVariables.armCount++;
            }
            this->renderLargeCharacter();
            break;

        case 30 ... 31:
            this->characterVariables.armCount++;
            this->renderLargeCharacter();
            PD::setColor(7);
            PD::fillRectangle(110 - 20, 0, 40, 176);
            break;

        case 32 ... 33:
            this->characterVariables.armCount++;
            this->renderLargeCharacter();
            PD::setColor(7);
            PD::fillRectangle(110 - 50, 0, 100, 176);
            break;

        case 34 ... 35:
            this->characterVariables.armCount++;
            this->renderLargeCharacter();
            PD::setColor(7);
            PD::fillRectangle(110 - 80, 0, 160, 176);
            break;

        case 36 ... 37:
            this->characterVariables.armCount++;
            PD::fillScreen(7);
            break;

        case 38 ... 44:
            this->characterVariables.armCount++;
            break;

        case 45 ... 137:
            this->characterVariables.armCount++;
            PD::drawBitmap(30, 36, Images::GameOverText);
            for (uint8_t i = 0; i < 220; i = i + 20) {
                PD::drawBitmap(i, this->characterVariables.armCount - 45, Images::GameOverText_Mask);
            }
            break;

        case 138 ... 171:
            this->characterVariables.armCount++;
            PD::drawBitmap(30, 36, Images::GameOverText);
            for (uint8_t i = 0; i < 220; i = i + 20) {
                PD::drawBitmap(i, this->characterVariables.armCount - 45, Images::GameOverText_Mask);
            }

            for (int16_t x = -18, i = 0; x < 220;) {

                PD::drawBitmap(x, 142 + (171 - characterVariables.armCount), Images::Fire[((PC::frameCount + (spacing[i] * 6)) % 60) / 5]);
                x = x + 23 + spacing[i];
                i++;

            }

            break;

        case 172 ... 221:
            this->characterVariables.armCount++;
            PD::drawBitmap(30, 36, Images::GameOverText);
            for (uint8_t i = 0; i < 220; i = i + 20) {
                PD::drawBitmap(i, this->characterVariables.armCount - 45, Images::GameOverText_Mask);
            }

            for (int16_t x = -18, i = 0; x < 220;) {

                PD::drawBitmap(x, 142, Images::Fire[((PC::frameCount + (spacing[i] * 6)) % 60) / 5]);
                x = x + 23 + spacing[i];
                i++;

            }

            break;

        case 222:
            PD::drawBitmap(30, 36, Images::GameOverText);
            if (PC::frameCount % 32 == 0) {
                launchParticles(random(32, 188), random(16, 120), PC::frameCount % 64 == 0);
            }


            for (int16_t x = -18, i = 0; x < 220;) {

                PD::drawBitmap(x, 142, Images::Fire[((PC::frameCount + (spacing[i] * 6)) % 60) / 5]);
                x = x + 23 + spacing[i];
                i++;

            }

            break;

    }



    // Handle player input ..

    if (PC::buttons.pressed(BTN_A)) {

        this->gameState = GameState::Title_Init; 

    }

}


void Game::renderLargeCharacter() {

    //                   0   1   2   3   4   5   6   7   8   9   0   1   2   3   4   5   6   7   8   9   0   1   2   3   4   5   6   7   8   9   0
    const int8_t x[] = { 0,  0,  0,  0,  0,  1,  2,  3,  4,  5,  6,  7,  7,  6,  5,  4,  3,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, };
    const int8_t y[] = { 0,  0,  0,  0,  0, -2, -4, -5, -5, -4, -2,  2,  4,  6,  7,  7,  6,  4,  2, -4, -8,-12,-16,-20,-24,-28,-20,-14, -8, -3,  1, };

    PD::drawBitmap(83, 60, Images::Body);
    PD::drawBitmap(79 - x[this->characterVariables.armCount], 120 + y[this->characterVariables.armCount], Images::Arm_Left);
    PD::drawBitmap(118 + x[this->characterVariables.armCount], 120 + y[this->characterVariables.armCount], Images::Arm_Right);
    
    if (PC::frameCount % 128 < 2) {

        PD::drawBitmap(99, 99, Images::EyesClosed);

    }

}