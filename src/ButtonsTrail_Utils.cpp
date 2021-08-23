#include "ButtonsTrail.h"
#include "sounds/Sounds.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


void Game::playTheme() {

    #ifdef SOUNDS

    constexpr char themes[1][19] = { "music/DarkB_01.raw" };

    //SoundTheme themeToPlay = static_cast<SoundTheme>(static_cast<uint8_t>(theme) + (playHellModeTrack ? (this->cookieSaveGame->gameC ? 1 : 0) : 0));

    if (this->mainThemeFile.openRO(themes[0])) {
        auto& music = Audio::play<0>(this->mainThemeFile);
        music.setLoop(true);
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

    #endif

}    