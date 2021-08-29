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
        11, 0, // Starting Pos Player
        11, 5, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        20, // Minimum moves
        0, 0, 0, 3, 1,12, 1, 1, 1, 1, 1, 1, 0, 0, 0,
        0, 0, 0, 1, 0, 2, 0, 0, 1, 0, 0, 1, 0, 0, 0,
        0, 0, 0,12, 0, 2, 1, 1, 1, 0, 0, 1, 0, 0, 0, 
        0, 0, 0,12, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 
        0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 
        0, 0, 0, 3, 1,12, 1, 1, 1, 2, 2, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_3_01[] = {
        2, // Mode
        5, 0, // Starting Pos Player
        7, 2, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        26, // Minimum moves
        0, 0, 0, 0, 0, 1, 1, 3, 1, 1,12,11, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 3, 0, 0, 1, 1, 5, 0, 0,
        0, 0, 1, 2, 1, 2, 1, 1, 1, 1, 4, 2,12, 0, 0,
        0, 0, 0, 2, 0, 3, 0, 0, 2, 0, 1, 0, 5, 0, 0,
        0, 0, 0, 2, 0,12, 0, 0, 2, 0, 1, 0, 0, 0, 0,
        0, 0, 1,12, 2, 2, 2, 2,12, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_3_02[] = {
        2, // Mode
        3, 0, // Starting Pos
        11, 4, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        26, // Minimum moves
        0, 0, 0, 1, 1, 1, 2, 2, 2, 1, 1, 1, 0, 0, 0, 
        0, 0, 0, 0, 4, 0, 4, 0, 4, 0, 4, 0, 0, 0, 0, 
        0, 0, 0,11, 2, 2, 2, 2, 2, 2, 2,12, 0, 0, 0, 
        0, 0, 0, 0, 4, 0, 4, 0, 4, 0, 4, 0, 0, 0, 0, 
        0, 0, 0, 1, 1, 1, 2, 2, 2, 1, 1, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_3_03[] = {
        2, // Mode
        4, 0, // Starting Pos
        8, 6, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        20, // Minimum moves
        0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 2, 1, 0, 4,12, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 2, 2, 2, 4, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 2, 4, 2, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 2, 2, 2, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1,11, 1, 0, 2, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_3_04[] = {
        2, // Mode
        0, 0, // Starting Pos
        13, 6, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        30, // Minimum moves
        2, 2, 2, 4, 2, 2, 2, 4, 2, 2, 2, 4, 2, 2, 2, 
        2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 2, 0, 
        2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 2, 0, 
        2, 2,12, 3, 2, 2, 2, 4, 2, 4, 2, 1, 1, 2, 0, 
        2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 2, 0, 
        2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 4, 0, 
        2, 3, 3, 3, 2, 3, 3, 3, 2, 2, 2, 4, 3, 4,11, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_3_05[] = {
        2, // Mode
        1, 0, // Starting Pos
        13, 0, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        30, // Minimum moves
        0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 2, 0, 1, 0, 
        0, 4, 1, 4, 0, 8, 2, 2, 2, 4, 2, 1, 0, 2, 0, 
        0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 2, 0, 2, 0, 
        0, 1, 0, 2, 0, 2, 3, 3, 3, 4, 3, 4, 2, 4, 0, 
        0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 2, 0, 2, 0, 
        0, 4, 1, 4, 0, 8, 2, 2, 2, 4, 1, 2, 0, 2, 0, 
        0,12, 0, 1, 1, 1, 0, 0, 0, 0, 2, 1, 0,11, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_3_06[] = {
        2, // Mode
        1, 0, // Starting Pos
        12, 0, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        33, // Minimum moves
        0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 
        0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 
        0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 
        0, 0, 0, 0, 1, 2, 3, 2, 3, 2, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 2, 2, 2, 1, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 2, 3, 3, 2, 3, 3, 1, 0, 
        0,12, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2,12,11, 
        0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_3_07[] = {
        2, // Mode
        7, 0, // Starting Pos
        10, 3, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        33, // Minimum moves
        0, 0, 0, 0, 8, 1, 1, 4, 2, 2,12, 0, 0, 0, 0, 
        0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 2, 1, 1, 2, 1, 1, 4, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0,11, 2, 2, 2, 2, 2, 8, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

}