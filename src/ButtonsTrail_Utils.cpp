#include "ButtonsTrail.h"
#include "sounds/Sounds.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


void Game::playTheme() {

    #ifdef SOUNDS

    constexpr char themes[1][19] = { "music/DarkB_01.raw" };

    switch (this->cookie->sfx) {

        case SoundEffects::Music:
        case SoundEffects::Both:

            if (this->mainThemeFile.openRO(themes[0])) {
                auto& music = Audio::play<0>(this->mainThemeFile);
                music.setLoop(true);
            }

            break;

        case SoundEffects::SFX:
        case SoundEffects::None:

            this->muteTheme();

    }

    #endif

}

void Game::muteTheme() {

    #ifdef SOUNDS
    Audio::stop<0>();
    #endif

}


void Game::playSoundEffect(SoundEffect soundEffect) {

    #ifdef SOUNDS

    switch (this->cookie->sfx) {

        case SoundEffects::SFX:
        case SoundEffects::Both:
                
            switch (soundEffect) {
                
                case SoundEffect::Tone_00:
                    Audio::play<1>(Sounds::sfx_Tone_00);    
                    break;
                
                case SoundEffect::Tone_01:
                    Audio::play<1>(Sounds::sfx_Tone_01);    
                    break;
                
                case SoundEffect::Tone_02:
                    Audio::play<1>(Sounds::sfx_Tone_02);    
                    break;
                
                case SoundEffect::Tone_03:
                    Audio::play<1>(Sounds::sfx_Tone_03);    
                    break;
                            
                case SoundEffect::Tone_04:
                    Audio::play<1>(Sounds::sfx_Tone_04);    
                    break;               
                            
                case SoundEffect::Tone_05:
                    Audio::play<1>(Sounds::sfx_Tone_05);    
                    break;               
                            
                case SoundEffect::Tone_06:
                    Audio::play<1>(Sounds::sfx_Tone_06);    
                    break;               

                case SoundEffect::Tone_07:
                    Audio::play<1>(Sounds::sfx_Tone_07);    
                    break;               

            }

            break;

        default: break;
        
    }  

    #endif

}    


void Game::initGame(uint8_t level) {

    const uint8_t *puzzle = Puzzles::puzzles[level];

    uint16_t idx = 0;

    int8_t mode = puzzle[idx++];
    this->gameStats.mode = static_cast<GameMode>(mode);

    // Retrieve player starting position ..

    int8_t startX = puzzle[idx++];
    int8_t startY = puzzle[idx++];

    this->player.init(Character::Player, startX, startY);


    // Retrieve other player starting position ..

    startX = puzzle[idx++];
    startY = puzzle[idx++];

    this->other.init(Character::Other, startX, startY);

    if (this->other.isActive()) {
        this->gameStats.puffOfSmoke = 41;
    }



    // Retrieve arrows (if defined) ..

    startX = puzzle[idx++];
    startY = puzzle[idx++];

    this->arrows[0].init(startX, startY);

    startX = puzzle[idx++];
    startY = puzzle[idx++];


    // Minimium number of moves

    this->gameStats.minimumMoves = puzzle[idx++];

    this->arrows[1].init(startX, startY);

    for (uint16_t y = 0; y < Constants::BoardHeight; y++){

        for (uint16_t x = 0; x < Constants::BoardWidth; x++){

            uint8_t data = puzzle[idx++];

            this->board[y][x] = static_cast<Tiles>(data);

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

            count = count + (board[y][x] == Tiles::None ? 1 : 0);

        }

        if (count == Constants::BoardWidth) {
            blankRow++;
        }
        else {
            break;
        }

    }

    this->gameStats.yOffset = 0 + (blankRow * Constants::CellHeight_PlusBorder / 2);
    this->gameStats.stars = 0;

}

bool Game::endOfGame() {

    if (this->gameStats.xOffset == 0 && !player.isMoving()) {

        for (int16_t y = 0; y < Constants::BoardHeight; y++) {

            for (int16_t x = 0; x < Constants::BoardWidth; x++) {

                if (x == player.getX() && y == player.getY()) {

                    if (board[y][x] == Tiles::Button2) {

                        return false;

                    }

                }
                else {

                    if (board[y][x] == Tiles::Button1 ||
                        board[y][x] == Tiles::Gem_SolidFloor ||
                        board[y][x] == Tiles::Gem_LinkedFloor ||
                        board[y][x] == Tiles::Gem_NormalFloor) {

                        return false;

                    }

                }

            }

        }


        // If this is the end of the game, check for exit tiles ..

        for (int16_t y = 0; y < Constants::BoardHeight; y++) {

            for (int16_t x = 0; x < Constants::BoardWidth; x++) {

                if (static_cast<Tiles>(this->board[y][x]) == Tiles::Exit) {

                    this->board[y][x] = Tiles::Button1;
                    return false;

                }

            }

        }

        return true;

    }
    else {

        return false;
    }

}

void Game::printBoard() {

    printf("--------------------------\n");

    for (int16_t y = 0; y < Constants::BoardHeight; y++) {

        for (int16_t x = 0; x < Constants::BoardWidth; x++) {

            if (static_cast<uint8_t>(this->board[y][x]) < 10) printf("_");
            printf("%i ", static_cast<uint8_t>(this->board[y][x]));

        }

        printf("\n");

    }

    printf("\n");

}

void Game::moveOther() {

    if (this->player.getXNew() < this->other.getX()) {

        if (this->canMoveToTile(this->other.getX() - 1, this->other.getY())) {

            this->other.moveLeft();
            removeTile(this->other);
            return;

        }

    }

    if (this->player.getXNew() > this->other.getX()) {

        if (this->canMoveToTile(this->other.getX() + 1, this->other.getY())) {

            this->other.moveRight();
            removeTile(this->other);
            return;

        }

    }

    if (this->player.getYNew() < this->other.getY()) {

        if (this->canMoveToTile(this->other.getX(), this->other.getY() - 1)) {

            this->other.moveUp();
            removeTile(this->other);
            return;

        }

    }

    if (this->player.getYNew() > this->other.getY()) {

        if (this->canMoveToTile(this->other.getX(), this->other.getY() + 1)) {

            this->other.moveDown();
            removeTile(this->other);
            return;

        }

    }

}

bool Game::canMoveToTile(int8_t x, int8_t y) {

    if (x < 0 || x > Constants::BoardWidth - 1 || y < 0 || y > Constants::BoardHeight - 1) return false;
    if (this->player.getXNew() == x && this->player.getYNew() == y) return false;

    switch (static_cast<Tiles>(this->board[y][x])) {

        case Tiles::None:
        case Tiles::Exit:
        case Tiles::Gem1_Only:
            return false;

        default:
            return true;

    }

}