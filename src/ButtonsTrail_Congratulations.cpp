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

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void Game::congratulations() { 

    PD::setColor(2);

    updateAndRenderParticles();

    PD::drawBitmap(53, 9, Images::GameOver);


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

    PD::drawBitmap(145, 50, Images::Body);
    PD::drawBitmap(141, 110 + this->characterVariables.armCount, Images::Arm_Left);
    PD::drawBitmap(180, 110 + this->characterVariables.armCount, Images::Arm_Right);
    
    if (PC::frameCount % 128 < 2) {

        PD::drawBitmap(161, 89, Images::EyesClosed);

    }


    // Draw lower border of fire ..

    int8_t spacing[] = { 0, 1, 0, -1, -2, 0, 1, 2, 1, 3, 0, 1, -2, 1 };

    for (int16_t x = -18, i = 0; x < 220;) {

        PD::drawBitmap(x, 142, Images::Fire[((PC::frameCount + (spacing[i] * 6)) % 60) / 5]);
        x = x + 23 + spacing[i];
        i++;

    }

    if (PC::frameCount % 32 == 0) {
        launchParticles(random(32, 188), random(16, 120), PC::frameCount % 64 == 0);
    }


    // Handle player input ..

    if (PC::buttons.pressed(BTN_A)) {

        this->gameState = GameState::Title_Init; 

    }

}
