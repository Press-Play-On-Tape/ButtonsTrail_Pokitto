#pragma once

namespace Images {

    #include "Tiles/Tile_01.h"
    #include "Tiles/Tile_02.h"
    #include "Tiles/Tile_03.h"
    #include "Tiles/Tile_04.h"
    #include "Tiles/Tile_05.h"
    #include "Tiles/Tile_06_00.h"
    #include "Tiles/Tile_06_01.h"
    #include "Tiles/Tile_06_02.h"

    const uint8_t * const Tiles[] = { 
        Tile_01, // Never used
        Tile_01,
        Tile_02,
        Tile_03,
        Tile_04,
        Tile_05, 
        Tile_06_00,
    };
   
    const uint8_t * const Tile_06[] = { 
        Tile_06_00, 
        Tile_06_01,
        Tile_06_02,
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
