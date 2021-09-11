#pragma once

#include "Pokitto.h"
#include "PokittoCookie.h"
#include "Enums.h"
#include "../puzzles/Puzzles.h"


class GameCookie : public Pokitto::Cookie {

	public:

		uint8_t initialised;
		uint8_t levelCurrent = 0;
		uint8_t levelMax = 0;
		SoundEffects sfx = SoundEffects::Both;
		uint8_t levelRating[200];

	public:

		void initialise() {

			this->initialised = COOKIE_INITIALISED;
			this->sfx = SoundEffects::Both;
			
			for (uint8_t i = 0; i < 200; i++) {
				levelRating[i] = 0;
			}

			this->levelCurrent = 0;
			this->levelMax = 0;
			this->saveCookie();

		}

};