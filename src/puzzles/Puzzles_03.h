#pragma once

namespace Puzzles {

    // 0 Blank
    // 1 Normal floor
    // 2 Solid floor #1
    // 3 Linked floor #2
    // 4 Double floor
    // 5 Button floor #1
    // 6 Button floor #2

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_3_00[] = {
        2, // Mode
        10, 0, // Starting Pos Player
        10, 5, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        15, // Minimum moves
        0, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 5, 1, 1, 1, 2, 2, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

}