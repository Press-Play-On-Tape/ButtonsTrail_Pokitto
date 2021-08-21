#include "ButtonsTrail.h"
#include "images/images.h"
#include "utils/Utils.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;



// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void Game::game_Init() {

    this->gameStats.reset();
    this->gameState = GameState::Game;

    this->gameStats.xOffset = -132;
    this->gameStats.exit = 0;
    this->gameStats.endOfGame = false;
    
}   


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void Game::game() {

    if (endOfGame() && !this->gameStats.endOfGame) {

        this->gameStats.endOfGame = true;

        #ifdef SOUNDS
        sound.tones(Sounds::Positive);
        #endif

    }


    // Update scrolling motion ..

    switch (this->gameStats.xOffset) {

        case -132:
            initGame(this->gameStats.level);
            this->gameStats.xOffset = this->gameStats.xOffset + 4;
            break;

        case -131 ... -1:
            this->gameStats.xOffset = this->gameStats.xOffset + 4;
            break;

        case 1 ... 127:
            this->gameStats.xOffset = this->gameStats.xOffset + 4;
            break;

        case 128 ... 256:
            this->gameStats.xOffset = -132;
            break;

        default: 
            break;

    }



    // if (PC::buttons.pressed(BTN_B)) this->gameStats.moves = 0;// SJH remove
    // if ((PC::buttons.pressed(BTN_B) || PC::buttons.repeat(BTN_B, 1)) && PC::buttons.pressed(BTN_UP)) { this->gameStats.level--; initGame(this->gameStats.level); }// SJH remove
    // if ((PC::buttons.pressed(BTN_B) || PC::buttons.repeat(BTN_B, 1)) && PC::buttons.pressed(BTN_DOWN)) { this->gameStats.level++; initGame(this->gameStats.level); }// SJH remove
    
    if (PC::buttons.pressed(BTN_B) || PC::buttons.repeat(BTN_B, 1)) { // Exit

        this->gameStats.exit++;

        if (this->gameStats.exit == 32) {

            this->gameState = GameState::Title_Init;
            this->gameStats.exit = 0;

        }
    }
    else {

        this->gameStats.exit = 0;

    }

    if (this->gameStats.xOffset == 0 && !player.isMoving() && !player.isDying() && !this->gameStats.endOfGame) {

        if (PC::buttons.pressed(BTN_LEFT) && player.getX() > -1)                             { player.moveLeft();   this->gameStats.moves++;   removeTile(); } 
        else if (PC::buttons.pressed(BTN_RIGHT) && player.getX() < Constants::BoardWidth)    { player.moveRight();  this->gameStats.moves++;   removeTile(); } 
        else if (PC::buttons.pressed(BTN_UP) && player.getY() > -1)                          { player.moveUp();     this->gameStats.moves++;   removeTile(); } 
        else if (PC::buttons.pressed(BTN_DOWN) && player.getY() < Constants::BoardHeight)    { player.moveDown();   this->gameStats.moves++;   removeTile(); } 

    }


    // Is the player on a 'blank' tile?

    if (!player.isDying() && (player.getXNew() < 0 || player.getXNew() == Constants::BoardWidth || player.getYNew() < 0 || player.getYNew() == Constants::BoardHeight || board[player.getYNew()][player.getXNew()] == static_cast<uint8_t>(Tiles::None))) {

        player.kill();
        
        if (this->gameStats.xOffset == 0) {

            #ifdef SOUNDS
            sound.tones(Sounds::Death);
            #endif

        }

    }
    
            
    // Render board ..

    if (!this->gameStats.endOfGame) {

        renderBoard();

    }
    renderHUD();


    // Update the game state ..

    if (this->player.update() && this->gameStats.xOffset == 0) {
    
        this->gameStats.xOffset = 4;

    }
                          
    for (FallingTile &fallingTile : this->fallingTiles) {

        if (fallingTile.isActive()) {

            fallingTile.update();
            
        }

    }

    if (PC::frameCount % 6 == 0) {
                
        for (Arrow &arrow : arrows) {

            arrow.update();

        }
        
    }

    if (this->gameStats.endOfGame) {

        uint8_t stars = 0;

        if (this->gameStats.moves < this->gameStats.minimumMoves + 2)           { stars = 3; }
        else if (this->gameStats.moves < this->gameStats.minimumMoves * 1.5)    { stars = 2; }
        else if (this->gameStats.moves < this->gameStats.minimumMoves * 3)      { stars = 1; }
        else                                                                    { stars = 0; }

        PD::drawBitmap(91, 66, (stars > 0 ? Images::Star_Filled : Images::Star_Hollow));
        PD::drawBitmap(105, 66, (stars > 1 ? Images::Star_Filled : Images::Star_Hollow));
        PD::drawBitmap(119, 66, (stars > 2 ? Images::Star_Filled : Images::Star_Hollow));

        if (this->gameStats.level + 1 == Puzzles::Count) {

            PD::drawBitmap(75, 80, Images::EndOfGame);
            updateAndRenderParticles();

            if (PC::frameCount % 32 == 0) launchParticles(random(32, 97), random(16, 48));

        }
        else {

            PD::drawBitmap(55, 80, Images::Congratulations);
            this->cookie->levelCurrent = this->gameStats.level + 1;
            if (this->gameStats.maxLevel < this->gameStats.level + 1) {
                this->cookie->levelMax = this->gameStats.level + 1;
            }

        }

        this->cookie->levelRating[this->gameStats.level] = stars;
        this->cookie->saveCookie();

        if (PC::buttons.pressed(BTN_A)) {

            if (this->gameStats.level + 1 == Puzzles::Count) {

                this->gameState = GameState::Title_Init;

            }
            else {

                this->gameStats.xOffset = 4;
                this->gameStats.level++;
                this->gameStats.moves = 0;
                this->gameStats.endOfGame = false;

            }

        }

    }

}

void Game::removeTile() {

    switch (static_cast<Tiles>(board[player.getY()][player.getX()])) {

        case Tiles::NormalFloor:

            #ifdef SOUNDS
            sound.tones(Sounds::Tone_01);
            #endif

            board[player.getY()][player.getX()] = static_cast<uint8_t>(Tiles::None);
           
            for (FallingTile &fallingTile : fallingTiles) {

                if (!fallingTile.isActive()) {

                    fallingTile.init(player.getX(), player.getY(), 3);
                    break;

                }

            }

            break;

        case Tiles::DoubleFloor:

            #ifdef SOUNDS
            sound.tones(Sounds::Tone_02);
            #endif

            board[player.getY()][player.getX()] = static_cast<uint8_t>(Tiles::NormalFloor);
            break;

        case Tiles::Button1:

            #ifdef SOUNDS
            sound.tones(Sounds::Tone_03);
            #endif

            board[player.getY()][player.getX()] = static_cast<uint8_t>(Tiles::Button2);
            break;

        case Tiles::Button2:

            #ifdef SOUNDS
            sound.tones(Sounds::Tone_03);
            #endif

            board[player.getY()][player.getX()] = static_cast<uint8_t>(Tiles::Button1);
            break;

        default: 
            #ifdef SOUNDS
            sound.tones(Sounds::Tone_01);
            #endif
            break;

    }
    
}

void Game::initGame(uint8_t level) {

    const uint8_t *puzzle = Puzzles::puzzles[level];

    uint16_t idx = 0;


    // Retrieve player starting position ..

    uint8_t startX = puzzle[idx++];
    uint8_t startY = puzzle[idx++];

    player.init(startX, startY);


    // Retrieve arrows (if defined) ..

    startX = puzzle[idx++];
    startY = puzzle[idx++];

    arrows[0].init(startX, startY);

    startX = puzzle[idx++];
    startY = puzzle[idx++];


    // Minimium number of moves

    this->gameStats.minimumMoves = puzzle[idx++];

    arrows[1].init(startX, startY);

    for (uint16_t y = 0; y < Constants::BoardHeight; y++){

        for (uint16_t x = 0; x < Constants::BoardWidth; x++){

            uint8_t data = puzzle[idx++];

            board[y][x] = data;

        }

    }


    // Clear falling tiles and players ..

    for (FallingTile &fallingTile : fallingTiles) {

        fallingTile.setActive(false);

    }


    // Scroll in ..

    this->gameStats.xOffset = -132;
    this->gameStats.endOfGame = false;


    // If last row is all zeroes we can render the board down 6px ..

    uint8_t count = 0;

    for (uint16_t x = 0; x < Constants::BoardWidth; x++){

        count = count + (board[Constants::BoardHeight - 1][x] == 0 ? 1 : 0);

    }

    this->gameStats.yOffset = count == Constants::BoardWidth ? 6 : 0;

}

bool Game::endOfGame() {

    if (this->gameStats.xOffset == 0 && !player.isMoving()) {

        for (int16_t y = 0; y < Constants::BoardHeight; y++) {

            for (int16_t x = 0; x < Constants::BoardWidth; x++) {

                if (x == player.getX() && y == player.getY()) {

                    if (board[y][x] == static_cast<uint8_t>(Tiles::Button2)) {

                        return false;

                    }

                }
                else {

                    if (board[y][x] == static_cast<uint8_t>(Tiles::Button1)) {

                        return false;

                    }

                }

            }

        }

        return true;

    }
    else {

        return false;
    }

}