//
// Created by Dan on 11/10/2017.
//

#ifndef GAMBIT_ENUMS_H
#define GAMBIT_ENUMS_H

#include <string>

enum piece {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    PIECE_DEFAULT
};

class pieceEnum {
public:
    static std::string pieceToString(int id);
};

enum color {
    WHITE,
    BLACK,
    COLOR_DEFAULT
};

class colorEnum {
public:
    static std::string colorToString(int id);
};

#endif //GAMBIT_ENUMS_H
