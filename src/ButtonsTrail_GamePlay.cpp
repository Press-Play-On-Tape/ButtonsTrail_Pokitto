#include "ButtonsTrail.h"
#include "utils/Utils.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;



// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void Game::game_Init() {

    this->gameStats.reset();
    this->gameState = GameState::Game;

    this->gameStats.xOffset = 224;
    this->gameStats.exit = 0;
    this->gameStats.endOfGame = false;
    this->gameStats.endOfGameCount = 0;
    
}   


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void Game::game() {

    if (endOfGame() && !this->gameStats.endOfGame) {

        this->gameStats.endOfGame = true;
        this->gameStats.endOfGameCount = 0;


        // Calculate stars ..

        if (this->gameStats.moves < this->gameStats.minimumMoves + 2)           { this->gameStats.stars = 3; }
        else if (this->gameStats.moves < this->gameStats.minimumMoves * 1.5)    { this->gameStats.stars = 2; }
        else if (this->gameStats.moves < this->gameStats.minimumMoves * 3)      { this->gameStats.stars = 1; }
        else                                                                    { this->gameStats.stars = 0; }

        #ifdef SOUNDS
        this->playSoundEffect(SoundEffect::Tone_04);
        #endif

    }
    else {

        if (this->gameStats.endOfGame && this->gameStats.endOfGameCount < 120) {

            this->gameStats.endOfGameCount++;

            switch (this->gameStats.endOfGameCount) {

                case 25: if (this->gameStats.stars > 0) this->playSoundEffect(SoundEffect::Tone_00); break;
                case 50: if (this->gameStats.stars > 1) this->playSoundEffect(SoundEffect::Tone_01); break;
                case 75: if (this->gameStats.stars > 2) this->playSoundEffect(SoundEffect::Tone_02); break;

            }

        }

    }


    // Update scrolling motion ..

    switch (this->gameStats.xOffset) {

        case -220:
            this->gameStats.xOffset = this->gameStats.xOffset - 4;
            this->gameStats.xOffset = 224;
            break;

        case -219 ... -1:
            this->gameStats.xOffset = this->gameStats.xOffset - 4;
            break;

        case 1 ... 223:
            this->gameStats.xOffset = this->gameStats.xOffset - 4;
            break;

        case 224:
            this->initGame(this->gameStats.level);
            this->gameStats.xOffset = this->gameStats.xOffset - 4;
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
            this->playSoundEffect(SoundEffect::Tone_07);
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
    
        this->gameStats.xOffset = -4;

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


        PD::drawBitmap( 91, 84, (this->gameStats.stars > 0 && this->gameStats.endOfGameCount >= 25 ? Images::Star_Filled : Images::Star_Hollow_Disabled));
        PD::drawBitmap(105, 84, (this->gameStats.stars > 1 && this->gameStats.endOfGameCount >= 50 ? Images::Star_Filled : Images::Star_Hollow_Disabled));
        PD::drawBitmap(119, 84, (this->gameStats.stars > 2 && this->gameStats.endOfGameCount >= 75 ? Images::Star_Filled : Images::Star_Hollow_Disabled));

        if (gameStats.endOfGameCount == 0) {

            if (this->gameStats.level + 1 < Puzzles::Count) {

                PD::drawBitmap(55, 66, Images::Congratulations);
                this->cookie->levelCurrent = this->gameStats.level + 1;
                if (this->gameStats.maxLevel < this->gameStats.level + 1) {
                    this->cookie->levelMax = this->gameStats.level + 1;
                }

            }

            this->cookie->levelRating[this->gameStats.level] = this->gameStats.stars;
            this->cookie->saveCookie();

        }

        if (this->gameStats.level + 1 == Puzzles::Count) {

            PD::drawBitmap(75, 66, Images::EndOfGame);
            updateAndRenderParticles();

            if (PC::frameCount % 32 == 0) launchParticles(random(32, 188), random(16, 120), PC::frameCount % 64 == 0);

        }
        else {

            PD::drawBitmap(55, 66, Images::Congratulations);

        }

        if (PC::buttons.pressed(BTN_A)) {

            if (this->gameStats.level + 1 == Puzzles::Count) {

                this->gameState = GameState::Title_Init;

            }
            else {

                this->gameStats.xOffset = -4;
                this->gameStats.level++;
                this->gameStats.moves = 0;
                this->gameStats.endOfGame = false;

            }

        }

    }

}

void Game::removeTile() {

    bool soundPlayed = false;

    switch (static_cast<Tiles>(board[player.getYNew()][player.getXNew()])) {

        case Tiles::Button1:

            #ifdef SOUNDS
            this->playSoundEffect(SoundEffect::Tone_03);
            soundPlayed = true;
            #endif

            break;

        default: break;

    }

    switch (static_cast<Tiles>(board[player.getY()][player.getX()])) {

        case Tiles::NormalFloor:

            #ifdef SOUNDS
            if (!soundPlayed) this->playSoundEffect(SoundEffect::Tone_05);
            soundPlayed = true;
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
            if (!soundPlayed) this->playSoundEffect(SoundEffect::Tone_06);
            soundPlayed = true;
            #endif

            board[player.getY()][player.getX()] = static_cast<uint8_t>(Tiles::NormalFloor);
            break;

        case Tiles::Button1:

            #ifdef SOUNDS
            if (!soundPlayed) this->playSoundEffect(SoundEffect::Tone_06);
            soundPlayed = true;
            #endif

            board[player.getY()][player.getX()] = static_cast<uint8_t>(Tiles::Button2);
            break;

        case Tiles::Button2:

            #ifdef SOUNDS
            if (!soundPlayed) this->playSoundEffect(SoundEffect::Tone_06);
            soundPlayed = true;
            #endif

            board[player.getY()][player.getX()] = static_cast<uint8_t>(Tiles::Button1);
            break;

        default: 
            break;

    }
    
}

void Game::initGame(uint8_t level) {

    const uint8_t *puzzle = Puzzles::puzzles[level];

    uint16_t idx = 0;


    // Retrieve player starting position ..

    int8_t startX = puzzle[idx++];
    int8_t startY = puzzle[idx++];

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

    this->gameStats.xOffset = 224;
    this->gameStats.endOfGame = false;


    // If last row is all zeroes we can render the board down 6px ..

    uint8_t blankRow = 0;

    for (uint16_t y = Constants::BoardHeight - 1; y > 0; y--) {

        uint8_t count = 0;

        for (uint16_t x = 0; x < Constants::BoardWidth; x++){

            count = count + (board[y][x] == static_cast<uint8_t>(Tiles::None) ? 1 : 0);

        }

        if (count == Constants::BoardWidth) {
            blankRow++;
        }
        else {
            break;
        }

    }

    this->gameStats.yOffset = 20 + (blankRow * Constants::CellHeight_PlusBorder / 2);
    this->gameStats.stars = 0;

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