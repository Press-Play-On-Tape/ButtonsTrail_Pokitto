#pragma once

namespace Images {

    #include "Player/Player_00.h"
    #include "Player/Player_01.h"
    #include "Player/Player_02.h"
    #include "Player/Player_03.h"

    const uint8_t * const Players[] = { 
        Player_00,
        Player_01,
        Player_02,
        Player_03,
    };

    #include "Player/Player_Falling_00.h"
    #include "Player/Player_Falling_01.h"

    const uint8_t * const Players_Falling[] = { 
        Player_Falling_00,
        Player_Falling_01,
    };

    #include "Player/Other_00.h"
    #include "Player/Other_01.h"

    const uint8_t * const Other[] = { 
        Other_00,
        Other_01,
    };
    
}
