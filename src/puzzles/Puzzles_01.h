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
    const uint8_t Puzzle_1_00[] = {
        0, // Mode
        3, 4, // Starting Pos
        255, 255, // Starting Pos Other
        11, 2, 0, 0, // Arrows
        20, // Minimum moves
        0, 0, 0, 0, 0, 1, 2, 2, 2, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 5, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_01[] = {
        0, // Mode
        2, 0, // Starting Pos
        255, 255, // Starting Pos Other
        7, static_cast<uint8_t>(-2), 12, static_cast<uint8_t>(-2), // Arrows
        10, // Minimum moves
        0, 0, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 5, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_02[] = {
        0, // Mode
        7, 4, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        14, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 5, 2, 6, 2, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_03[] = {
        0, // Mode
        4, 3, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        15, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 5, 1, 6, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 5, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 1, 1, 0, 5, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 5, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_04[] = {
        0, // Mode
        5, 4, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        18, // Minimum moves
        0, 0, 0, 0, 0, 5, 1, 5, 1, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 5, 2, 5, 2, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_05[] = {
        0, // Mode
        6, 2, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        22, // Minimum moves
        0, 0, 0, 0, 0, 0, 5, 1, 1, 0, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 1, 2, 0, 5, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_06[] = {
        0, // Mode
        3, 2, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        16, // Minimum moves
        0, 0, 0, 0, 0, 5, 4, 5, 1, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 1, 1, 0, 5, 1, 4, 6, 5, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_07[] = {
        0, // Mode
        3, 3, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        27, // Minimum moves
        0, 0, 0, 0, 1, 5, 1, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 6, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 1, 5, 1, 1, 5, 0, 0, 0, 
        0, 0, 0, 0, 0, 5, 1, 6, 1, 1, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_08[] = {
        0, // Mode
        3, 1, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        29, // Minimum moves
        0, 0, 0, 0, 1, 1, 1, 1, 1, 6, 1, 1, 0, 0, 0, 
        0, 0, 0, 1, 5, 1, 0, 5, 0, 5, 0, 5, 1, 0, 0, 
        0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 
        0, 0, 0, 5, 1, 5, 1, 5, 1, 0, 1, 6, 1, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_09[] = {
        0, // Mode
        7, 2, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        35, // Minimum moves
        0, 0, 0, 5, 1, 1, 1, 0, 0, 1, 6, 5, 0, 0, 0, 
        0, 0, 0, 1, 5, 1, 4, 6, 1, 4, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 5, 0, 0, 0, 0, 
        0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 5, 5, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_10[] = {
        0, // Mode
        5, 3, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        33, // Minimum moves
        0, 0, 0, 1, 1, 2, 4, 6, 1, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 0, 1, 0, 1, 0, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 5, 0, 1, 0, 5, 0, 1, 1, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 5, 1, 1, 1, 0, 5, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 0, 5, 0, 0, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 1, 4, 1, 1, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_11[] = {
        0, // Mode
        3, 1, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        33, // Minimum moves
        0, 0, 0, 0, 0, 6, 4, 4, 1, 1, 1, 5, 0, 0, 0, 
        0, 0, 0, 1, 1, 4, 0, 5, 0, 1, 0, 4, 0, 0, 0, 
        0, 0, 0, 0, 0, 6, 1, 1, 1, 5, 1, 6, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 5, 0, 0, 5, 1, 1, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_12[] = {
        0, // Mode
        3, 4, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        37, // Minimum moves
        0, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 1, 6, 4, 5, 1, 1, 1, 1, 1, 5, 1, 0, 0, 
        0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 
        0, 0, 0, 1, 0, 1, 0, 1, 1, 5, 4, 1, 5, 0, 0, 
        0, 0, 0, 1, 1, 2, 1, 1, 5, 0, 4, 0, 1, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 6, 1, 5, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_13[] = {
        0, // Mode
        7, 3, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        48, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6, 5, 0, 
        0, 5, 1, 4, 6, 0, 0, 0, 0, 1, 1, 4, 0, 5, 0, 
        0, 4, 5, 0, 5, 0, 0, 0, 1, 5, 0, 1, 0, 0, 0, 
        0, 5, 0, 0, 1, 0, 0, 1, 4, 1, 1, 5, 0, 0, 0, 
        0, 0, 0, 1, 5, 4, 1, 0, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 5, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_14[] = {
        0, // Mode
        4, 4, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        35, // Minimum moves
        0, 0, 0, 5, 0, 0, 0, 0, 0, 5, 4, 1, 5, 0, 0, 
        0, 0, 0, 1, 5, 1, 5, 1, 1, 0, 1, 0, 1, 0, 0, 
        0, 0, 0, 1, 1, 5, 1, 0, 1, 1, 6, 1, 1, 0, 0, 
        0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 
        0, 0, 0, 5, 1, 1, 5, 0, 0, 1, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 1, 5, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_15[] = {
        0, // Mode
        3, 4, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        32, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6, 1, 0, 0, 
        0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 4, 5, 0, 0, 0, 
        0, 0, 0, 0, 5, 0, 1, 0, 5, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 1, 1, 6, 5, 1, 1, 1, 4, 0, 0, 0, 0, 
        0, 0, 0, 1, 0, 1, 0, 0, 6, 0, 6, 0, 0, 0, 0, 
        0, 0, 0, 0, 5, 1, 1, 1, 4, 1, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_16[] = {
        0, // Mode
        3, 4, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        41, // Minimum moves
        0, 0, 5, 6, 4, 1, 1, 6, 1, 6, 1, 1, 0, 0, 0, 
        0, 0, 0, 1, 5, 6, 0, 1, 5, 1, 0, 1, 1, 0, 0, 
        0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 5, 0, 0, 
        0, 0, 0, 5, 0, 0, 0, 0, 6, 4, 5, 0, 1, 0, 0, 
        0, 0, 0, 1, 5, 4, 4, 5, 4, 0, 1, 1, 6, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 1, 1, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_17[] = {
        0, // Mode
        4, 4, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        39, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 5, 0, 1, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 4, 5, 4, 4, 1, 5, 0, 0, 
        0, 0, 0, 5, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 
        0, 0, 0, 1, 0, 4, 1, 1, 0, 0, 1, 1, 6, 0, 0, 
        0, 0, 0, 1, 1, 5, 0, 5, 0, 5, 1, 0, 1, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 5, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_18[] = {
        0, // Mode
        3, 2, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        29, // Minimum moves
        0, 0, 0, 0, 0, 5, 1, 0, 1, 1, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 2, 4, 5, 1, 6, 4, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 5, 1, 0, 0, 5, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_19[] = {
        0, // Mode
        10, 0, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        30, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 5, 1, 1, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 5, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 4, 6, 1, 4, 0, 0, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 4, 5, 1, 4, 5, 0, 0, 0, 
        0, 0, 0, 0, 5, 1, 1, 6, 0, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_20[] = {
        0, // Mode
        8, 2, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        52, // Minimum moves
        0, 0, 6, 1, 1, 4, 6, 1, 5, 0, 0, 0, 0, 0, 0, 
        0, 0, 4, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 1, 0, 0, 1, 5, 1, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 1, 5, 0, 1, 0, 0, 0, 0, 5, 4, 5, 0, 0, 
        0, 0, 5, 4, 1, 4, 1, 1, 5, 1, 4, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 5, 1, 5, 6, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_21[] = {
        0, // Mode
        2, 2, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        27, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 5, 6, 5, 1, 2, 0, 0, 0, 0, 0, 0, 
        0, 0, 1, 1, 4, 5, 1, 1, 1, 1, 5, 6, 0, 0, 0, 
        0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 6, 1, 5, 0, 0, 
        0, 0, 0, 0, 5, 6, 6, 5, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };


    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_22[] = {
        0, // Mode
        2, 2, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        37, // Minimum moves
        0, 0, 0, 5, 6, 5, 0, 0, 0, 5, 6, 5, 0, 0, 0, 
        0, 0, 0, 2, 1, 1, 1, 0, 1, 2, 1, 1, 0, 0, 0, 
        0, 0, 1, 4, 0, 0, 1, 0, 1, 0, 0, 4, 1, 0, 0, 
        0, 0, 0, 1, 0, 0, 4, 1, 4, 0, 0, 1, 0, 0, 0, 
        0, 0, 0, 6, 5, 6, 1, 0, 1, 6, 5, 5, 0, 0, 0, 
        0, 0, 0, 0, 5, 1, 0, 0, 0, 1, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };


    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_23[] = {
        0, // Mode
        6, 2, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        41, // Minimum moves
        0, 0, 0, 5, 1, 5, 1, 5, 1, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 5, 1, 5, 1, 5, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 5, 1, 5, 1, 5, 1, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 5, 1, 5, 1, 5, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 5, 1, 5, 1, 5, 1, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 5, 1, 5, 1, 5, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_24[] = {
        0, // Mode
        0, 5, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        55, // Minimum moves
        0, 0, 5, 6, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 1, 1, 1, 0, 0, 0, 6, 5, 6, 0, 5, 6, 0, 
        0, 0, 1, 0, 1, 0, 0, 0, 5, 4, 5, 0, 1, 5, 0, 
        0, 0, 1, 0, 1, 0, 0, 0, 0, 4, 0, 0, 5, 0, 0, 
        0, 5, 1, 4, 4, 0, 1, 5, 1, 4, 6, 1, 1, 0, 0, 
        1, 4, 5, 6, 1, 1, 4, 1, 5, 6, 6, 4, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const uint8_t Puzzle_1_25[] = {
        0, // Mode
        2, 2, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        39, // Minimum moves
        0, 0, 0, 0, 5, 1, 5, 6, 5, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 
        0, 0, 1, 1, 4, 0, 0, 2, 0, 0, 0, 5, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 2, 4, 4, 6, 6, 5, 0, 0, 
        0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 5, 0, 0, 0, 
        0, 0, 5, 1, 6, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const uint8_t Puzzle_1_26[] = {
        0, // Mode
        2, 2, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        37, // Minimum moves
        0, 0, 0, 5, 1, 5, 6, 5, 0, 0, 0, 0, 0, 5, 0,
        0, 0, 0, 1, 0, 6, 5, 6, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 1, 6, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 1, 0, 0, 1, 0, 5, 5, 6, 0, 0, 1, 0,
        0, 0, 0, 1, 1, 1, 4, 1, 4, 6, 1, 1, 1, 5, 0,
        0, 0, 0, 0, 0, 0, 5, 0, 5, 5, 6, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_27[] = {
        0, // Mode
        13, 0, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        41, // Minimum moves
        0, 2, 1, 4, 0, 0, 0, 0, 0, 0, 0, 4, 1, 2, 0, 
        0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
        0, 2, 1, 4, 1, 1, 1, 1, 4, 1, 1, 4, 1, 2, 0, 
        0, 6, 0, 6, 0, 0, 6, 0, 1, 0, 0, 1, 0, 5, 0, 
        0, 5, 1, 5, 0, 0, 5, 6, 1, 0, 0, 1, 6, 5, 0, 
        0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_28[] = {
        0, // Mode
        5, 5, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        64, // Minimum moves
        6, 5, 1, 4, 2, 1, 1, 5, 1, 1, 2, 4, 1, 1, 2, 
        5, 6, 0, 5, 0, 2, 0, 0, 2, 0, 0, 6, 5, 0, 1, 
        0, 1, 0, 0, 0, 1, 5, 1, 1, 0, 0, 5, 0, 0, 1, 
        0, 1, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 1, 
        6, 5, 0, 0, 0, 1, 1, 5, 1, 0, 0, 0, 0, 6, 6, 
        5, 6, 1, 1, 1, 2, 0, 0, 2, 1, 1, 1, 1, 5, 6, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
    const uint8_t Puzzle_1_29[] = {
        0, // Mode
        0, 3, // Starting Pos
        255, 255, // Starting Pos Other
        0, 0, 0, 0, // Arrows
        60, // Minimum moves
        0, 0, 0, 5, 6, 5, 0, 0, 5, 1, 5, 0, 5, 6, 5, 
        0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 2, 
        0, 2, 1, 1, 0, 2, 1, 1, 5, 6, 4, 1, 1, 1, 4, 
        1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 
        0, 5, 1, 1, 1, 4, 6, 1, 5, 2, 1, 5, 6, 1, 1, 
        0, 0, 0, 0, 0, 5, 1, 0, 5, 6, 1, 0, 5, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

}