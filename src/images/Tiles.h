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
    #include "Tiles/Tile_11.h"

    const uint8_t * const Tiles[] = { 
        Tile_01, // Never used
        Tile_01,
        Tile_02,
        Tile_03,
        Tile_04,
        Tile_05, 
        Tile_06_00,
        Tile_03,  // 07 Gem Linked Floor 
        Tile_01,  // 08 Gem Normal Floor
        Tile_02,  // 09 Gem Solid Floor 
        Tile_11,  // 11 Exit
        Tile_01,  // 10 Gem Only
    };
   
    const uint8_t * const Tile_06[] = { 
        Tile_06_00, 
        Tile_06_01,
        Tile_06_02,
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

    #include "Tiles/Gem_00.h"
    #include "Tiles/Gem_01.h"
    #include "Tiles/Gem_02.h"
    #include "Tiles/Gem_03.h"

    const uint8_t * const Gems[] = { 
        Gem_00,
        Gem_01,
        Gem_02,
        Gem_03,
    };

}
