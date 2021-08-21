#pragma once

#include "../utils/Utils.h"

class FallingTile { 

    private:

        uint8_t x;
        uint8_t y;
        bool active = false;
        uint8_t yOffset = 0;
        uint8_t numberOfImages = 0;

    public:

        uint8_t getX()                          { return this->x; }
        uint8_t getY()                          { return this->y; }
        uint8_t getYOffset()                    { return this->yOffset; }
        bool isActive()                         { return this->active; }

        void setX(uint8_t val)                  { this->x = val; }
        void setY(uint8_t val)                  { this->y = val; }
        void getYOffset(uint8_t val)            { this->yOffset = val; }
        void setActive(bool val)                { this->active = val; }
        void setNumberOfImages(uint8_t val)     { this->numberOfImages = val; }

    public:
    
        void init(uint8_t x, uint8_t y, uint8_t numberOfImages) {
            
            this->x = x;
            this->y = y;
            this->yOffset = 0;
            this->active = true;
            this->numberOfImages = numberOfImages;

        }

        uint8_t getImageIndex() { 
            
            return this->yOffset / 10; 
            
        }

        void update() {

            if (this->active) {

                this->yOffset = yOffset + 2;

                if (this->yOffset >= this->numberOfImages * 10) {

                    this->active = false;

                }

            }

        }

};