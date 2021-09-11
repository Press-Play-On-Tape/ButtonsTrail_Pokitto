#include "ButtonsTrail.h"
#include "images/images.h"
#include "utils/Utils.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


void Game::renderBoard() {


    // Render falling tiles ..
                
    for (FallingTile &fallingTile : fallingTiles) {

        if (fallingTile.isActive()) {

            PD::drawBitmap(Constants::Board_XOffset + (fallingTile.getX() * Constants::CellWidth_PlusBorder), 
                           Constants::Board_YOffset + (fallingTile.getY() * Constants::CellHeight_PlusBorder) + fallingTile.getYOffset() + this->gameStats.yOffset, 
                           Images::Tile_Falling[fallingTile.getImageIndex() + (fallingTile.isLinked() ? 3 : 0)]);

        }

    }


    // Render board ..

    for (uint16_t y = 0; y < Constants::BoardHeight; y++){

        for (uint16_t x = 0; x < Constants::BoardWidth; x++){

            switch (static_cast<Tiles>(board[y][x])) {

                case Tiles::None:
                    break;

                case Tiles::NormalFloor:
                case Tiles::DoubleFloor:
                case Tiles::SolidFloor:
                case Tiles::LinkedFloor:
                case Tiles::Button1:
                case Tiles::Exit:
                case Tiles::LinkedFloor_Alt:
                
                    PD::drawBitmap(Constants::Board_XOffset + this->gameStats.xOffset + (x * Constants::CellWidth_PlusBorder), 
                                   Constants::Board_YOffset + (y * Constants::CellHeight_PlusBorder) + this->gameStats.yOffset, 
                                   Images::Tiles[static_cast<uint8_t>(board[y][x])]);
                    break;

                case Tiles::Gem_LinkedFloor:
                case Tiles::Gem_NormalFloor:
                case Tiles::Gem_SolidFloor:
                    {
                        uint8_t frame = (PC::frameCount % 64) / 16;

                        PD::drawBitmap(Constants::Board_XOffset + this->gameStats.xOffset + (x * Constants::CellWidth_PlusBorder), 
                                    Constants::Board_YOffset + (y * Constants::CellHeight_PlusBorder) + this->gameStats.yOffset, 
                                    Images::Tiles[static_cast<uint8_t>(board[y][x])]);
                        PD::drawBitmap(Constants::Board_XOffset + this->gameStats.xOffset + (x * Constants::CellWidth_PlusBorder), 
                                    Constants::Board_YOffset + (y * Constants::CellHeight_PlusBorder) + this->gameStats.yOffset - 4, 
                                    Images::Gems[frame]);

                    }
                    break;

                case Tiles::Gem_Only:
                    {
                        uint8_t frame = (PC::frameCount % 64) / 16;
                        PD::drawBitmap(Constants::Board_XOffset + this->gameStats.xOffset + (x * Constants::CellWidth_PlusBorder), 
                                    Constants::Board_YOffset + (y * Constants::CellHeight_PlusBorder) + this->gameStats.yOffset - 4, 
                                    Images::Gems[frame]);

                    }
                    break;


                case Tiles::Button2:
                    {
                        uint8_t idx = (PC::frameCount % 72);            
                        idx = (idx >= 24 ? 0 : idx / 8);

                        PD::drawBitmap(Constants::Board_XOffset + this->gameStats.xOffset + (x * Constants::CellWidth_PlusBorder), 
                                       Constants::Board_YOffset + (y * Constants::CellHeight_PlusBorder) + this->gameStats.yOffset, 
                                       Images::Tile_06[idx]);

                    }

                    break;

            }

        }

    }



    // Render arrows .. (if defined)

    for (Arrow &arrow : arrows) {

        if (arrow.getX() > 0 || arrow.getY() > 0) {
    
            PD::drawBitmap(Constants::Board_XOffset + this->gameStats.xOffset + (arrow.getX() * Constants::CellWidth_PlusBorder) - 1, 
                           Constants::Board_YOffset + (arrow.getY() * Constants::CellHeight_PlusBorder) + arrow.getYOffset() + this->gameStats.yOffset - 1, 
                           Images::Arrow);


        }

    }


    // Render player ..

    if (this->gameStats.xOffset == 0) {

        uint8_t frame = (PC::frameCount % 32) / 16;

        if (this->player.getDirection() == Direction::Left) frame = frame + 2;

        if (player.isDying()) {

            if (player.isMoving()) {

                PD::drawBitmap(Constants::Board_XOffset + (player.getX() * Constants::CellWidth_PlusBorder) + player.getXOffset(), 
                               Constants::Board_YOffset + (player.getY() * Constants::CellHeight_PlusBorder) + player.getYOffset() + this->gameStats.yOffset - 4, 
                               Images::Players[frame]);

            }
            else {

                PD::drawBitmap(Constants::Board_XOffset + (player.getX() * Constants::CellWidth_PlusBorder), 
                               Constants::Board_YOffset + (player.getY() * Constants::CellHeight_PlusBorder) + player.getYDyingOffset_1() + this->gameStats.yOffset - 3, 
                               Images::Players_Falling[this->player.getImageIndex()]);

            }
    
        }
        else {

            PD::drawBitmap(Constants::Board_XOffset + (player.getX() * Constants::CellWidth_PlusBorder) + player.getXOffset(), 
                           Constants::Board_YOffset + (player.getY() * Constants::CellHeight_PlusBorder) + player.getYOffset() + this->gameStats.yOffset - 4, 
                           Images::Players[frame]);

        }
        
    }


    // Render puff of smoke ..

    if (this->gameStats.xOffset == 0 && this->other.isActive() && this->gameStats.puffOfSmoke > 0) {

        if (this->gameStats.puffOfSmoke == 41) this->playSoundEffect(SoundEffect::Tone_08);

        PD::drawBitmap(Constants::Board_XOffset + (other.getX() * Constants::CellWidth_PlusBorder) + other.getXOffset() - 15, 
                        Constants::Board_YOffset + (other.getY() * Constants::CellHeight_PlusBorder) + other.getYOffset() + this->gameStats.yOffset - 17, 
                        Images::Explosion[this->gameStats.puffOfSmoke / 6]);
        
    }


    // Render other ..

    if (this->gameStats.xOffset == 0 && this->other.isActive() && this->gameStats.puffOfSmoke < 24) {

        uint8_t frame = (PC::frameCount % 32) / 16;

        if (this->other.getDirection() == Direction::Left) frame = frame + 2;
        if (this->gameStats.mode == GameMode::Attack) frame = frame + 4;

        PD::drawBitmap(Constants::Board_XOffset + (other.getX() * Constants::CellWidth_PlusBorder) + other.getXOffset(), 
                        Constants::Board_YOffset + (other.getY() * Constants::CellHeight_PlusBorder) + other.getYOffset() + this->gameStats.yOffset - 4, 
                        Images::Other[frame]);
        
    }

}


void Game::renderHUD() {

    for (uint8_t x = 0; x < 220; x = x + 21) {
        PD::drawBitmap(x, 0, Images::Background_Top);
        PD::drawBitmap(x, 168, Images::Background_Bottom);
    }

    PD::drawBitmap(0, 14, Images::Web_00);
    PD::drawBitmap(204, 14, Images::Web_01);
    PD::drawBitmap(0, 154, Images::Web_02);
    PD::drawBitmap(204, 154, Images::Web_03);

    PD::drawBitmap(26, 3, Images::HUD_Level);

    {
        uint8_t digits[3] = {};
        uint8_t x = 75;

        extractDigits(digits, this->gameStats.level);

        for (uint8_t i = 0; i < 3; ++i) {

            if (digits[i] == 1) x = x - 3;

        }

        for (uint8_t i = 0; i < 3; ++i) {
            PD::drawBitmap(x, 3, Images::Numbers_HUD[digits[i]]);
            x = x - (digits[i] == 1 ? 5 : 8);
        }

    }


    PD::drawBitmap(134, 3, Images::HUD_Moves);

    {
        uint8_t digits[3] = {};
        uint8_t x = 188;

        extractDigits(digits, this->gameStats.moves < 999 ? static_cast<uint16_t>(this->gameStats.moves) : static_cast<uint16_t>(999));

        for (uint8_t i = 0; i < 3; ++i) {

            if (digits[i] == 1) x = x - 3;

        }
        
        for (uint8_t i = 0; i < 3; ++i) {
            PD::drawBitmap(x, 3, Images::Numbers_HUD[digits[i]]);
            x = x - (digits[i] == 1 ? 5 : 8);
        }

    }

}