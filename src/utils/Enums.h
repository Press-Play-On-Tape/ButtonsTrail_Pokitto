#pragma once

#define SOUNDS
#define COOKIE_INITIALISED 39

namespace Constants {

    constexpr uint8_t FallingTilesCount = 16;
    constexpr uint8_t BoardWidth = 15;
    constexpr uint8_t BoardHeight = 9;

    // Normal

    constexpr uint8_t CellWidth_PlusBorder = 14;
    constexpr uint8_t CellHeight_PlusBorder = 14;
    constexpr uint8_t Board_XOffset = 6;
    constexpr uint8_t Board_YOffset = 28;

    // Zoom

    constexpr uint8_t CellWidth_Zoom_PlusBorder = 13;
    constexpr uint8_t CellHeight_Zoom_PlusBorder = 10;
    constexpr uint8_t Board_XOffset_Zoom = 4;
    constexpr uint8_t Board_YOffset_Zoom = 15;
    constexpr uint8_t ParticlesMax = 50;

}

enum class GameState : uint8_t {
    Splash_Init,
    Splash,
    Title_Init,
    Title,
    LevelSelect_Init,
    LevelSelect,
    Instructions_Init,
    Instructions,
    Game_Init,
    Game,
    Congratulations_Init,
    Congratulations,
};

enum class Tiles : uint8_t {
    None,               // 0
    NormalFloor,        // 1
    SolidFloor,         // 2
    LinkedFloor,        // 3
    DoubleFloor,        // 4
    Button1,            // 5
    Button2,            // 6
    Exit = 10,          // 10
    Gem_Only = 12,           // 12
    LinkedFloor_Alt = 13,  // 13
    Gem_NormalFloor     = 21,    // 21
    Gem_SolidFloor      = 22,     // 22
    Gem_LinkedFloor     = 23,    // 23
};

enum class Direction : uint8_t {
    Up,
    Down,
    Left,
    Right
};

enum class GameMode : uint8_t {
    NoOther,
    LockStep,
    Attack
};

enum class Character : uint8_t {
    Player,
    Other,
};

enum class SoundEffect : uint8_t {
    Tone_00,
    Tone_01,
    Tone_02,
    Tone_03,
    Tone_04,
    Tone_05,
    Tone_06,
    Tone_07,
    Tone_08,
    Tone_09,
};

enum class TitleScreenMode : uint8_t {
    NewGame,
    LevelSelect,
    SoundEffects
};

inline TitleScreenMode &operator++(TitleScreenMode &c ) {
    c = static_cast<TitleScreenMode>( (static_cast<uint8_t>(c) + 1) % 4 );
    return c;
}

inline TitleScreenMode operator++(TitleScreenMode &c, int ) {
    TitleScreenMode result = c;
    ++c;
    return result;
}

inline TitleScreenMode &operator--(TitleScreenMode &c ) {
    if (static_cast<uint8_t>(c) > 0) {
        c = static_cast<TitleScreenMode>( (static_cast<uint8_t>(c) - 1) % 4 );
    }
    else {
        c = static_cast<TitleScreenMode>( 3 );
    }
    return c;
}

inline TitleScreenMode operator--(TitleScreenMode &c, int ) {
    TitleScreenMode result = c;
    --c;
    return result;
}

enum class SoundEffects : uint8_t {
    Both,
    Music,
    SFX,
    None
};

inline SoundEffects &operator++(SoundEffects &c ) {
    c = static_cast<SoundEffects>( (static_cast<uint8_t>(c) + 1) % 4 );
    return c;
}

inline SoundEffects operator++(SoundEffects &c, int ) {
    SoundEffects result = c;
    ++c;
    return result;
}

inline SoundEffects &operator--(SoundEffects &c ) {
    if (static_cast<uint8_t>(c) > 0) {
        c = static_cast<SoundEffects>( (static_cast<uint8_t>(c) - 1) % 4 );
    }
    else {
        c = static_cast<SoundEffects>( 3 );
    }
    return c;
}

inline SoundEffects operator--(SoundEffects &c, int ) {
    SoundEffects result = c;
    --c;
    return result;
}