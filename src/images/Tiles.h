#pragma once

namespace Images {

    #include "Tiles/Tile_00.h"
    #include "Tiles/Tile_01.h"
    #include "Tiles/Tile_02.h"
    #include "Tiles/Tile_03.h"
    #include "Tiles/Tile_04.h"
    #include "Tiles/Tile_05.h"
    #include "Tiles/Tile_06.h"

    const uint8_t * const Tiles[] = { 
        Tile_00,
        Tile_01,
        Tile_02,
        Tile_03,
        Tile_04,
        Tile_05,
        Tile_06,
    };
   
    #include "Tiles/Skull_00.h"
    #include "Tiles/Skull_01.h"
    #include "Tiles/Skull_02.h"
    #include "Tiles/Skull_03.h"
    #include "Tiles/Skull_04.h"

    const uint8_t * const Skulls[] = { 
        Skull_00,   
        Skull_01,   
        Skull_02,   
        Skull_03,   
        Skull_04,   
    };

    #include "Tiles/Tile_Falling_00.h"
    #include "Tiles/Tile_Falling_01.h"
    #include "Tiles/Tile_Falling_02.h"

    const uint8_t * const Tile_Falling[] = { 
        Tile_Falling_00,
        Tile_Falling_01,
        Tile_Falling_02,
    };   


}
