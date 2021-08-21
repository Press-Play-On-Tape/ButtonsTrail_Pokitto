#include "ButtonsTrail.h"
#include "images/images.h"
#include "utils/Utils.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


void Game::launchParticles(int16_t x, int16_t y) {

    for (int i = 0; i < Constants::ParticlesMax; i++) {

        particles[i].setX(x);
        particles[i].setY(y);
        particles[i].setVelX(random(-4, 5));
        particles[i].setVelY(random(-1, 6));
        particles[i].setCounter(random(10, 46));
        particles[i].setSize(random(1, 3));
    
    }

}

void Game::updateAndRenderParticles() {

    for ( int i = 0; i < Constants::ParticlesMax; i++) {

        particles[i].update();

        if ( particles[i].render() ) { // the dot should be rendered

            int pSize = particles[i].getSize();

            if (pSize == 1) {
                PD::drawPixel( particles[i].getX(), particles[i].getY(), 1);
            } 
            else {
                PD::drawRectangle( particles[i].getX(), particles[i].getY(), pSize, pSize);
            }

        }

    }

}
