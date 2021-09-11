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
    
}   


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void Game::instructions() {


    // Draw upper border ..

    for (uint8_t x = 0; x < 220; x = x + 28) {
        PD::drawBitmap(x, 26, Images::Divider);
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


    // Draw lower border ..

    for (uint8_t x = 0; x < 220; x = x + 28) {
        PD::drawBitmap(x, 151, Images::Divider);
    }


    // Handle player actions ..

    if (PC::buttons.pressed(BTN_LEFT) && this->gameStats.instruction > 0) { 

        this->gameStats.instruction--;

    }         

    if (PC::buttons.pressed(BTN_RIGHT) || PC::buttons.pressed(BTN_A)) {

        if (this->gameStats.instruction < 3) { 

            this->gameStats.instruction++;

        }
        else {

            this->gameState = GameState::Game_Init;

        }

    }         


    // Render page ..

    PD::drawBitmap(39, 5, Images::Instructions);
    PD::setColor(6);

    switch (this->gameStats.instruction) {

        case 0:

            PD::drawBitmap(157, 32, Images::Body);
            PD::drawBitmap(153, 92 + this->characterVariables.armCount, Images::Arm_Left);
            PD::drawBitmap(192, 92 + this->characterVariables.armCount, Images::Arm_Right);
            
            if (PC::frameCount % 128 < 2) {

                PD::drawBitmap(173, 71, Images::EyesClosed);

            }

            PD::drawBitmap(214, 18, Images::Arrow_Right);

            PD::setCursor(6, 57);
            PD::print("Move between the tiles to");

            PD::setCursor(6, 69);
            PD::print("turn on all the switches");

            PD::setCursor(6, 81);
            PD::print("and retrieve any gems.");

            PD::setCursor(6, 98);
            PD::print("Be careful though as some");

            PD::setCursor(6, 110);
            PD::print("tiles will collapse when ");

            PD::setCursor(6, 122);
            PD::print("crossed preventing you");

            PD::setCursor(6, 134);
            PD::print("from back-tracking!");

            break;

        case 1:
            PD::drawBitmap(205, 18, Images::Arrow_Left);
            PD::drawBitmap(214, 18, Images::Arrow_Right);

            PD::setColor(2, 14);
            PD::setCursor(6, 58);
            PD::print("Floor Tiles");
            PD::setColor(8, 14);
            PD::setCursor(6, 57);
            PD::print("Floor Tiles");
            PD::setColor(6, 0);

            PD::drawBitmap(6, 72, Images::Tiles[1]);
            PD::setCursor(26, 76);
            PD::print("Normal: falls away once crossed.");
 
            PD::drawBitmap(6, 90, Images::Tiles[4]);
            PD::setCursor(26, 94);
            PD::print("Double: can be crossed twice.");

            PD::drawBitmap(6, 108, Images::Tiles[2]);
            PD::setCursor(26, 112);
            PD::print("Solid: never falls when crossed.");

            PD::drawBitmap(6, 126, Images::Tiles[3]);
            PD::setCursor(26, 130);
            PD::print("Linked: all tiles fall together.");
            break;

        case 2:
            {
                PD::drawBitmap(205, 18, Images::Arrow_Left);
                PD::drawBitmap(214, 18, Images::Arrow_Right);

                PD::setColor(2, 14);
                PD::setCursor(6, 58);
                PD::print("Switches and Gems");
                PD::setColor(8, 14);
                PD::setCursor(6, 57);
                PD::print("Switches and Gems");
                PD::setColor(6, 0);

                PD::drawBitmap(6, 72, Images::Tiles[static_cast<uint8_t>(Tiles::Button1)]);
                PD::setCursor(26, 76);
                PD::print("Off: switch is in OFF position.");

                uint8_t idx = (PC::frameCount % 72);
                idx = (idx >= 24 ? 0 : idx / 8);

                PD::drawBitmap(6, 91, Images::Tile_06[idx]);
                PD::setCursor(26, 95);
                PD::print("On: switch is in ON position.");

                PD::drawBitmap(6, 110, Images::Tiles[2]);
                PD::drawBitmap(6, 108, Images::Gems[idx]);
                PD::setCursor(26, 113);
                PD::print("Gems: gather all of them!");

            }

            break;

        case 3:
            {
                PD::drawBitmap(205, 18, Images::Arrow_Left);
                PD::drawBitmap(214, 18, Images::Arrow_Right);

                PD::setColor(2, 14);
                PD::setCursor(6, 58);
                PD::print("Shadows");
                PD::setColor(8, 14);
                PD::setCursor(6, 57);
                PD::print("Shadows");
                PD::setColor(6, 0);

                uint8_t frame = (PC::frameCount % 32) / 16;

                PD::drawBitmap(6, 72, Images::Other[frame]);
                PD::setCursor(26, 76);
                PD::print("Red: moves in lockstep with you.");
                PD::setCursor(26, 88);
                PD::print("Watch they don't step on tiles");
                PD::setCursor(26, 100);
                PD::print("you will need to cross later.");

                frame = (frame == 0 ? 1 : 0) + 6;

                PD::drawBitmap(6, 114, Images::Other[frame]);
                PD::setCursor(26, 120);
                PD::print("Green: will move towards you and");
                PD::setCursor(26, 132);
                PD::print("try to block your path to glory!");

            }
            break;

    }

}
