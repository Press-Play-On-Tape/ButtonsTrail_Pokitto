#include "ButtonsTrail.h"
#include "images/images.h"
#include "utils/Utils.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


void Game::setup(GameCookie *cookie) {

    this->cookie = cookie;

}

void Game::loop() {

    PD::clear();
    PC::buttons.pollButtons();

    switch (this->gameState) {

        case GameState::Splash:
            splashScreen();
            break;

        case GameState::Title_Init:
            title_Init();
            title();
            break;

        case GameState::Title:
            title();
            break;

        case GameState::LevelSelect_Init:
            levelSelect_Init();
            levelSelect();
            break;

        case GameState::LevelSelect:
            levelSelect();
            break;

        case GameState::Instructions_Init:
            instructions_Init();
            instructions();
            break;

        case GameState::Instructions:
            instructions();
            break;

        case GameState::Game_Init:
            game_Init();
            game();
            break;

        case GameState::Game:
            game();
            break;

        case GameState::Congratulations_Init:
            congratulations_Init();
            congratulations();
            break;

        case GameState::Congratulations:
            congratulations();
            break;
    }

}

