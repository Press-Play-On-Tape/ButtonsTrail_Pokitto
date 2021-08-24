#pragma once

namespace Images {

    #include "Tiles/Tile_01.h"
    #include "Tiles/Tile_02.h"
    #include "Tiles/Tile_03.h"
    #include "Tiles/Tile_04.h"
    #include "Tiles/Tile_05_00.h"
    #include "Tiles/Tile_05_01.h"
    #include "Tiles/Tile_05_02.h"
    #include "Tiles/Tile_06.h"

    const uint8_t * const Tiles[] = { 
        Tile_01, // Never used
        Tile_01,
        Tile_02,
        Tile_03,
        Tile_04,
        Tile_05_00, // Never Used
        Tile_06,
    };
   
    const uint8_t * const Tile_05[] = { 
        Tile_05_00, 
        Tile_05_01,
        Tile_05_02,
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
