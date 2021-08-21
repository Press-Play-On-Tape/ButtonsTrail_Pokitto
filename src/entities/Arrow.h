#pragma once

#include "../utils/Utils.h"
#include "../utils/Enums.h"


class Arrow { 

    private:

        int8_t x;
        int8_t y;
        uint8_t yOffset = 0;
        Direction direction = Direction::Down;

    public:

        int8_t getX()                           { return this->x; }
        int8_t getY()                           { return this->y; }
        uint8_t getYOffset()                    { return this->yOffset; }

        void setX(int8_t val)                   { this->x = val; }
        void setY(int8_t val)                   { this->y = val; }
        void getYOffset(uint8_t val)            { this->yOffset = val; }

    public:

        void init(uint8_t x, uint8_t y) {

            this->x = x;
            this->y = y;
            this->yOffset = 0;
            this->direction = Direction::Down;

        }

        void update() {

            switch (this->direction) {

                case Direction::Up:

                    this->yOffset = yOffset - 1;

                    if (this->yOffset == 0) {
                        this->direction = Direction::Down;
                    }

                    break;

                case Direction::Down:

                    this->yOffset = yOffset + 1;

                    if (this->yOffset == 4) {
                        this->direction = Direction::Up;
                    }

                    break;

            }

        }

};