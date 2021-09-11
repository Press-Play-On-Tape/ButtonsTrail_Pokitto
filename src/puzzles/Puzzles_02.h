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
    const uint8_t Puzzle_2_99[] = {
        2, // Mode
        3, 7, // Starting Pos Player
        3, 0, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        28, // Minimum moves
        0, 0, 0, 1, 1, 1, 4, 2, 1, 1, 1, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 4, 0, 1, 0, 0, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 4, 0, 1, 0, 0, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 4, 0, 3, 0, 0,13, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 4, 0, 1, 0, 0, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 4, 0, 1, 0, 0, 1, 0, 0, 0, 
        0, 0, 0, 1, 1, 1, 4, 1, 4,21, 0, 1, 0, 0, 0, 
        0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_00[] = {
        1, // Mode
        5, 2, // Starting Pos Player
        255, 255, // Starting Pos Other
        10, 0, 0, 0, // Arrows
        15, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 2,22, 2, 1, 10,0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_01[] = {
        1, // Mode
        8, 3, // Starting Pos Player
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        15, // Minimum moves
        0, 0, 0, 0, 0,22, 1, 1, 3, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_02[] = {
        1, // Mode
        5, 0, // Starting Pos Player
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        15, // Minimum moves
        0, 0, 0, 0, 0, 1, 1, 1, 1, 3, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 3, 0, 1, 0, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 2, 1, 1,10, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0,23, 1, 1, 1, 3, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_03[] = {
        1, // Mode
        6, 1, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        9, // Minimum moves
        0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 3, 1, 1, 1, 3, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 3, 1, 3, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 3,21, 2,21, 3, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 3, 3, 3, 1,10, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };


    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_04[] = {
        1, // Mode
        11, 0, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        29, // Minimum moves
        0, 0, 1,21, 1,21, 1, 1,21, 2,21, 1, 0, 0, 0, 
        0, 0, 3, 1, 0, 1, 0, 3, 0, 1, 0, 1, 0, 0, 0, 
        0, 0, 1, 1, 0, 1, 0, 3, 0, 1, 0, 1, 0, 0, 0, 
        0, 0, 1, 1,21, 2,21, 1, 0,21, 1,21, 0, 0, 0, 
        0, 0,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_05[] = {
        1, // Mode
        7, 1, // Starting Pos
        7, 3, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        15, // Minimum moves
        0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 3, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 2, 1, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 2, 1, 1, 1, 0,21, 3, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 1, 3, 2, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 3,10, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_06[] = {
        1, // Mode
        5, 0, // Starting Pos
        6, 1, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        17, // Minimum moves
        0, 0, 0, 0, 0, 1, 3, 1, 3, 1, 3, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 3, 0,21, 1,21, 3, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 3, 1,21, 1,21, 3, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,10, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 3, 1, 3, 1, 3, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_07[] = {
        1, // Mode
        5, 0, // Starting Pos
        7, 4, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        9, // Minimum moves
        0, 0, 0, 0, 0, 1, 1, 3, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 3, 1, 1, 1,21, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1, 3, 1,10, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_08[] = {
        1, // Mode
        4, 1, // Starting Pos
        4, 3, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        9, // Minimum moves
        0, 0, 0, 0, 0, 1,21, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 1, 1, 1, 1, 3,10, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 1, 1, 1, 3, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_09[] = {
        1, // Mode
        4, 6, // Starting Pos
        7, 3, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        18, // Minimum moves
        0, 0, 0, 0, 1, 1, 1,21, 1, 1, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 3, 0, 0, 0, 3, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 3, 1, 3, 2, 3, 1,21, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 3, 0, 0, 0, 3, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 1, 1, 3, 1, 1,10, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };


    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_10[] = {
        1, // Mode
        6, 0, // Starting Pos
        7, 0, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        8, // Minimum moves
        0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 2, 2,10, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0,21, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_11[] = {
        1, // Mode
        6, 0, // Starting Pos
        8, 1, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        8, // Minimum moves
        0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 2, 2, 2,10, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0,21, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_12[] = {
        1, // Mode
        6, 1, // Starting Pos
        5, 1, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        8, // Minimum moves
        0, 0, 0, 0, 0, 3,22, 2,21, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 2,10, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 3,22, 1,21, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_13[] = {
        1, // Mode
        6, 0, // Starting Pos
        5, 1, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        12, // Minimum moves
        0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 1,21, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1,21, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 3, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1, 1,10, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_14[] = {
        1, // Mode
        7, 0, // Starting Pos
        8, 6, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        20, // Minimum moves
        0, 0, 0, 0, 0,21, 1, 2, 1,21, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 2, 2, 2, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0,21, 1, 2, 1,21, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 3, 1, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 3, 1, 2, 1, 3, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 3, 1, 2, 1, 3, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 3, 3, 0, 3, 3, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_15[] = {
        1, // Mode
        7, 0, // Starting Pos Player
        7, 6, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        46, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
        0, 0, 0, 1, 1, 3, 1, 1, 1, 3, 1, 1, 0, 0, 0, 
        0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 
        0,22, 4, 2, 2, 1, 1, 1, 1, 1, 2, 2, 4,22, 0, 
        0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 
        0, 0, 0, 4, 2, 2, 2, 2, 2, 2, 2, 3, 0, 0, 0, 
        0, 0, 0,22, 1, 3, 2, 2, 2, 3, 1,22, 0, 0, 0, 
        0, 0, 0, 0, 4, 4, 0,10, 0, 4, 4, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_16[] = {
        1, // Mode
        7, 0, // Starting Pos Player
        7, 8, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        28, // Minimum moves
        0, 0, 0, 0,21, 2, 2, 4, 2, 2,21, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 4, 1, 4, 4, 4, 1, 4, 0, 0, 0, 0, 
        0, 0, 0, 0,21, 0, 0, 3, 0, 0,21, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 3, 0, 1, 0, 3, 0, 0, 0, 0, 0, 
    };

    const uint8_t Puzzle_2_17[] = {
        1, // Mode
        2, 1, // Starting Pos Player
        2, 5, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        17, // Minimum moves
        0, 0, 0, 1, 1, 1, 0, 3, 1,21, 0, 0, 0, 0, 0, 
        0, 0, 1, 1, 3, 4, 1, 1, 1, 4, 3, 10,0, 0, 0, 
        0, 0, 0, 3, 1, 1, 0, 1, 1,21, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 
        0, 0, 1, 1, 3, 1, 1, 1, 3, 1, 1, 0, 0, 0, 0, 
        0, 0, 0, 1, 3, 1, 1, 1, 3, 1, 1, 0, 0, 0, 0, 
        0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_2_18[] = {
        1, // Mode
        3, 0, // Starting Pos Player
        11, 8, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        40, // Minimum moves
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,22, 0, 0, 0, 
        0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
        0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 
        0, 0, 0, 1, 1, 1, 1,10, 1, 1, 1, 1, 0, 0, 0, 
        0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
        0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 
        0, 0, 0,22, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
    };

    const uint8_t Puzzle_2_19[] = {
        1, // Mode
        10, 0, // Starting Pos Player
        4, 0, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        47, // Minimum moves
        0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0,22, 2, 2, 2, 2, 2,22, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0,22, 4, 4, 2, 1, 1,22, 0, 0, 0, 0, 
        0, 0, 0, 0, 2, 0, 0, 4, 0, 0, 2, 0, 0, 0, 0, 
        0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 0, 
    };

    const uint8_t Puzzle_2_20[] = {
        1, // Mode
        4, 3, // Starting Pos Player
        4, 2, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        16, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0, 0,  
        0, 0, 0, 0, 0, 0, 2, 2, 2, 3, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 1, 1, 3, 2, 2, 4, 0, 0, 0, 0, 
        0, 0, 0, 2, 2, 1, 1, 1, 1, 2, 2, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 1, 1, 4, 2,21, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };


}