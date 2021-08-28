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
    #include "Tiles/Tile_07.h"
    #include "Tiles/Tile_08.h"
    #include "Tiles/Tile_09.h"
    #include "Tiles/Tile_10_00.h"
    #include "Tiles/Tile_10_01.h"
    #include "Tiles/Tile_10_02.h"
    #include "Tiles/Tile_11.h"
    #include "Tiles/Tile_12.h"

    const uint8_t * const Tiles[] = { 
        Tile_01, // Never used
        Tile_01,
        Tile_02,
        Tile_03,
        Tile_04,
        Tile_05, 
        Tile_06_00,
        Tile_07, 
        Tile_08,
        Tile_09, 
        Tile_10_00, 
        Tile_11, 
        Tile_12, 
    };
   
    const uint8_t * const Tile_06[] = { 
        Tile_06_00, 
        Tile_06_01,
        Tile_06_02,
    };
   
    const uint8_t * const Tile_10[] = { 
        Tile_10_00, 
        Tile_10_01,
        Tile_10_02,
    };

    #include "Tiles/Tile_Falling_00.h"
    #include "Tiles/Tile_Falling_01.h"
    #include "Tiles/Tile_Falling_02.h"
    #include "Tiles/Tile_Falling_03.h"
    #include "Tiles/Tile_Falling_04.h"
    #include "Tiles/Tile_Falling_05.h"

    const uint8_t * const Tile_Falling[] = { 
        Tile_Falling_00,
        Tile_Falling_01,
        Tile_Falling_02,
        Tile_Falling_03,
        Tile_Falling_04,
        Tile_Falling_05,
    };   

}
