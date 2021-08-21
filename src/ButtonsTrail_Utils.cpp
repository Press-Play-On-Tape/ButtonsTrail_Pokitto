#include "ButtonsTrail.h"
#include "sounds/Sounds.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


void Game::playTheme(uint8_t trackNumber) {

    #ifdef SOUNDS

    // constexpr char themes[3][17] = { "music/Hex_01.raw", "music/Hex_02.raw", "music/Hex_03.raw" };

    // switch (this->cookie->sfx) {

    //     case SoundEffects::Music:
    //     case SoundEffects::Both:

    //         if (this->mainThemeFile.openRO(themes[trackNumber])) {
    //             auto& music = Audio::play<0>(mainThemeFile);
    //             music.setLoop(true);
    //         }

    //         break;

    //     case SoundEffects::SFX:
    //     case SoundEffects::None:

    //         this->muteTheme();

    // }

    #endif

}

void Game::muteTheme() {

    #ifdef SOUNDS
    Audio::stop<0>();
    #endif

}


void Game::playSoundEffect(SoundEffect soundEffect) {

    #ifdef SOUNDS

    switch (soundEffect) {
        
        case SoundEffect::Tone_00:
        {
  auto note = Audio::Note(10)
                    .wave(2)
                    .duration(750)
                    .volume(127);        
note.play();
        }
         //   Audio::play<1>(Sounds::sfx_Tone_00);    
            break;
        
        case SoundEffect::Tone_01:
            Audio::play<1>(Sounds::sfx_Tone_01);    
            break;
        
        case SoundEffect::Tone_02:
            Audio::play<1>(Sounds::sfx_Tone_02);    
            break;
                
    }

    #endif

}    