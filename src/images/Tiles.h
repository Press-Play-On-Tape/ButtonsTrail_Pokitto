#pragma once

namespace Images {

    #include "Tiles/Tile_00.h"
    #include "Tiles/Tile_01.h"
    #include "Tiles/Tile_02.h"
    #include "Tiles/Tile_03.h"
    #include "Tiles/Tile_04.h"
    #include "Tiles/Tile_05.h"
    #include "Tiles/Tile_06_00.h"
    #include "Tiles/Tile_06_01.h"
    #include "Tiles/Tile_06_02.h"
    #include "Tiles/Tile_10.h"

    const uint8_t * const Tiles[] = { 
        Tile_00, // 00 Never used
        Tile_01, // 01 Normal
        Tile_02, // 02 Solid
        Tile_03, // 03 Linked
        Tile_04, // 04 Double
        Tile_05, // 05 Button1
        Tile_00, // 06 Button2
        Tile_00, // 07 Never used
        Tile_00, // 08 Never used
        Tile_00, // 09 Never used
        Tile_10, // 10 Exit
        Tile_00, // 11 Never used
        Tile_01, // 12 Gem Only
        Tile_00, // 13 Never used
        Tile_00, // 14 Never used
        Tile_00, // 15 Never used
        Tile_00, // 16 Never used
        Tile_00, // 17 Never used
        Tile_00, // 18 Never used
        Tile_00, // 19 Never used
        Tile_00, // 20 Never used
        Tile_01, // 22 Gem Normal Floor
        Tile_02, // 23 Gem Solid Floor 
        Tile_03, // 21 Gem Linked Floor 
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
