#include "ButtonsTrail.h"
#include "images/images.h"
#include "utils/Utils.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;

// ----------------------------------------------------------------------------
//  Initialise state ..
//
void Game::instructions_Init() {
    
    this->gameState = GameState::Instructions;
    this->gameStats.start = 0;
    
}   


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void Game::instructions() {


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

    PD::drawBitmap(155, 35, Images::Body);
    PD::drawBitmap(151, 95 + this->characterVariables.armCount, Images::Arm_Left);
    PD::drawBitmap(190, 95 + this->characterVariables.armCount, Images::Arm_Right);
    
    if (PC::frameCount % 128 < 2) {

        PD::drawBitmap(171, 74, Images::EyesClosed);

    }


    // Draw lower border ..

    for (uint8_t x = 0; x < 220; x = x + 28) {
        PD::drawBitmap(x, 150, Images::Divider);
    }


    // Delay for 'good luck' ..

    if (this->gameStats.start < 80) { this->gameStats.start++; }


    // Handle player actions ..

    if (PC::buttons.pressed(BTN_LEFT) && this->gameStats.instruction > 0) { 

        this->gameStats.instruction--;

    }         

    if (PC::buttons.pressed(BTN_RIGHT) || PC::buttons.pressed(BTN_A)) {

        if (this->gameStats.instruction < 2) { 

            this->gameStats.instruction++;
            this->gameStats.start = 0;

        }
        else {

            this->gameState = GameState::Game_Init;

        }

    }         


    // Render page ..

    PD::drawBitmap(0, 0, Images::Instructions);
    PD::setColor(6);

    switch (this->gameStats.instruction) {

        case 0:
            PD::drawBitmap(143, 67, Images::Arrow_Right);

            PD::setCursor(6, 65);
            PD::print("Move between the floor tiles to");

            PD::setCursor(6, 76);
            PD::print("turn on all the button switches.");

            PD::setCursor(6, 94);
            PD::print("But be careful though as some");

            PD::setCursor(6, 105);
            PD::print("floor tiles will fall when crossed");

            PD::setCursor(6, 116);
            PD::print("preventing you from back-tracking!");

            break;

        case 1:
            PD::drawBitmap(136, 67, Images::Arrow_Left);
            PD::drawBitmap(143, 67, Images::Arrow_Right);

            PD::setCursor(6, 65);
            PD::print("Floor Tiles");

            PD::drawBitmap(6, 79, Images::Tiles[1]);
            PD::setCursor(26, 81);
            PD::print("Normal: falls away once crossed.");

            PD::drawBitmap(6, 99, Images::Tiles[4]);
            PD::setCursor(26, 101);
            PD::print("Double: can be crossed twice.");

            PD::drawBitmap(6, 119, Images::Tiles[3]);
            PD::setCursor(26, 121);
            PD::print("Solid: never falls when crossed.");
            break;

        case 2:
            PD::drawBitmap(136, 67, Images::Arrow_Left);
            PD::drawBitmap(143, 67, Images::Arrow_Right);

            PD::setCursor(6, 65);
            PD::print("Button Switches");

            PD::drawBitmap(6, 79, Images::Tiles[static_cast<uint8_t>(Tiles::SolidFloor1)]);
            PD::drawBitmap(8, 81, Images::Skulls[0]);
            PD::setCursor(26, 81);
            PD::print("Off: switch is in OFF position.");

            PD::drawBitmap(6, 99, Images::Tiles[static_cast<uint8_t>(Tiles::SolidFloor1)]);
            PD::drawBitmap(8, 101, Images::Skulls[(PC::frameCount % 60) / 12]);
            PD::setCursor(26, 101);
            PD::print("On: switch is in ON position.");

            if (this->gameStats.start >= 80) {
            
                PD::setCursor(6, 129);
                PD::print("Press A to start !");

            }
            else {
            
                PD::setCursor(6, 129);
                PD::print("Hold B to quit.");

            }

            break;

    }

}
