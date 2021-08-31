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

        if (PC::buttons.pressed(BTN_LEFT) && player.getX() > -1) {

            if (this->other.isActive() && this->player.getX() - 1 == this->other.getX() && this->player.getY() == this->other.getY()) {

            }
            else {

                player.moveLeft();   
                this->gameStats.moves++;   
                removeTile(this->player); 

                if (this->other.isActive()) {  

                    switch (this->gameStats.mode) {

                        case GameMode::LockStep:

                            if (this->canMoveToTile(this->other.getX() - 1, this->other.getY())) {

                                this->other.moveLeft();
                                removeTile(this->other);
                                break;

                            }

                            break;

                        case GameMode::Attack:

                            this->moveOther();
                            break;

                        default: break;

                    }

                }

            }
            
        }

        else if (PC::buttons.pressed(BTN_RIGHT) && player.getX() < Constants::BoardWidth) {

            if (this->other.isActive() && this->player.getX() + 1 == other.getX() && this->player.getY() == other.getY()) {

            }
            else {

                player.moveRight();  
                this->gameStats.moves++;   
                removeTile(this->player); 

                if (this->other.isActive()) {  

                    switch (this->gameStats.mode) {

                        case GameMode::LockStep:

                            if (this->canMoveToTile(this->other.getX() + 1, this->other.getY())) {

                                this->other.moveLeft();
                                removeTile(this->other);
                                break;

                            }

                            break;

                        case GameMode::Attack:

                            this->moveOther();
                            break;

                        default: break;

                    }

                }

            }

        } 

        else if (PC::buttons.pressed(BTN_UP) && player.getY() > -1) { 

            if (this->other.isActive() && this->player.getX() == this->other.getX() && this->player.getY() - 1 == this->other.getY()) {

            }
            else {

                player.moveUp();     
                this->gameStats.moves++;   
                removeTile(this->player); 

                if (this->other.isActive()) {  

                    switch (this->gameStats.mode) {

                        case GameMode::LockStep:

                            if (this->canMoveToTile(this->other.getX(), this->other.getY() - 1)) {

                                this->other.moveLeft();
                                removeTile(this->other);
                                break;

                            }

                            break;

                        case GameMode::Attack:

                            this->moveOther();
                            break;

                        default: break;

                    }

                }

            }

        } 

        else if (PC::buttons.pressed(BTN_DOWN) && player.getY() < Constants::BoardHeight) { 

            if (this->other.isActive() && this->player.getX() == this->other.getX() && this->player.getY() + 1 == this->other.getY()) {

            }
            else {

                player.moveDown();   
                this->gameStats.moves++;   
                removeTile(this->player); 

                if (this->other.isActive()) {  

                    switch (this->gameStats.mode) {

                        case GameMode::LockStep:

                            if (this->canMoveToTile(this->other.getX(), this->other.getY() + 1)) {

                                this->other.moveLeft();
                                removeTile(this->other);
                                break;

                            }

                            break;

                        case GameMode::Attack:

                            this->moveOther();
                            break;

                        default: break;

                    }

                }

            }

        }       

    }


    // Is the player on a 'blank' tile?

    if (!player.isDying() && (player.getXNew() < 0 || player.getXNew() == Constants::BoardWidth || player.getYNew() < 0 || player.getYNew() == Constants::BoardHeight 
        || this->board[player.getYNew()][player.getXNew()] == Tiles::None
        || this->board[player.getYNew()][player.getXNew()] == Tiles::Exit
        || this->board[player.getYNew()][player.getXNew()] == Tiles::Gem1_Only)) {

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

    this->other.update();

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

void Game::removeTile(Player &character) {

    bool soundPlayed = false;

    if (character.getCharacterType() == Character::Player) {

        switch (static_cast<Tiles>(board[character.getYNew()][character.getXNew()])) {

            case Tiles::Button1:

                #ifdef SOUNDS
                this->playSoundEffect(SoundEffect::Tone_03);
                soundPlayed = true;
                #endif

                break;

            case Tiles::Gem_NormalFloor:

                #ifdef SOUNDS
                this->playSoundEffect(SoundEffect::Tone_03);
                soundPlayed = true;
                #endif

                board[character.getYNew()][character.getXNew()] = Tiles::NormalFloor;
                break;

            case Tiles::Gem_SolidFloor:

                #ifdef SOUNDS
                this->playSoundEffect(SoundEffect::Tone_03);
                soundPlayed = true;
                #endif

                board[character.getYNew()][character.getXNew()] = Tiles::SolidFloor;
                break;

            case Tiles::Gem_LinkedFloor:

                #ifdef SOUNDS
                this->playSoundEffect(SoundEffect::Tone_03);
                soundPlayed = true;
                #endif

                board[character.getYNew()][character.getXNew()] = Tiles::LinkedFloor;
                break;

            default: break;

        }

    }

    switch (static_cast<Tiles>(board[character.getY()][character.getX()])) {

        case Tiles::NormalFloor:
        case Tiles::Gem_NormalFloor:

            #ifdef SOUNDS
            if (!soundPlayed && character.getCharacterType() == Character::Player) this->playSoundEffect(SoundEffect::Tone_05);
            soundPlayed = true;
            #endif

            if (character.getCharacterType() == Character::Player) {

                board[character.getY()][character.getX()] = Tiles::None;

            }
            else {
                
                switch (static_cast<Tiles>(board[character.getY()][character.getX()])) {

                    case Tiles::Gem_NormalFloor:
                        board[character.getY()][character.getX()] = Tiles::Gem1_Only;
                        break;

                    default:
                        board[character.getY()][character.getX()] = Tiles::None;
                        break;

                } 

            }
           
            for (FallingTile &fallingTile : fallingTiles) {

                if (!fallingTile.isActive()) {

                    fallingTile.init(character.getX(), character.getY(), 3, false);
                    break;

                }

            }

            break;

        case Tiles::LinkedFloor:
        case Tiles::Gem_LinkedFloor:

            #ifdef SOUNDS
            if (!soundPlayed && character.getCharacterType() == Character::Player) this->playSoundEffect(SoundEffect::Tone_05);
            soundPlayed = true;
            #endif

            for (uint16_t y = 0; y < Constants::BoardHeight; y++){

                for (uint16_t x = 0; x < Constants::BoardWidth; x++){

                    Tiles test = static_cast<Tiles>(board[y][x]);

                    switch (test) {

                        case Tiles::LinkedFloor:

                            board[y][x] = Tiles::None;
                            for (FallingTile &fallingTile : this->fallingTiles) {

                                if (!fallingTile.isActive()) {

                                    fallingTile.init(x, y, 3, true);
                                    break;

                                }

                            }

                            break;

                        case Tiles::Gem_LinkedFloor:

                            if (x != character.getXOld() || y != character.getYOld()) {
                                
                                board[y][x] = Tiles::Gem1_Only;

                            }
                            else {

                                board[y][x] = Tiles::None;

                            }

                            for (FallingTile &fallingTile : this->fallingTiles) {

                                if (!fallingTile.isActive()) {

                                    fallingTile.init(x, y, 3, true);
                                    break;

                                }

                            }

                            break;

                        default: break;

                    }

                }

            }

            break;

        case Tiles::DoubleFloor:

            #ifdef SOUNDS
            if (!soundPlayed && character.getCharacterType() == Character::Player) this->playSoundEffect(SoundEffect::Tone_06);
            soundPlayed = true;
            #endif

            board[character.getY()][character.getX()] = Tiles::NormalFloor;
            break;

        case Tiles::Button1:

            if (character.getCharacterType() == Character::Player) {

                #ifdef SOUNDS
                if (!soundPlayed && character.getCharacterType() == Character::Player) this->playSoundEffect(SoundEffect::Tone_06);
                soundPlayed = true;
                #endif

                board[character.getY()][character.getX()] = Tiles::Button2;

            }
            break;

        case Tiles::Gem_SolidFloor:

            if (character.getCharacterType() == Character::Player) {

                #ifdef SOUNDS
                if (!soundPlayed) this->playSoundEffect(SoundEffect::Tone_06);
                soundPlayed = true;
                #endif

                board[character.getY()][character.getX()] = Tiles::SolidFloor;

            }

            break;

        case Tiles::Button2:

            #ifdef SOUNDS
            if (!soundPlayed && character.getCharacterType() == Character::Player) this->playSoundEffect(SoundEffect::Tone_06);
            soundPlayed = true;
            #endif

            board[character.getY()][character.getX()] = Tiles::Button1;
            break;

        default: 
            break;

    }
    
}
