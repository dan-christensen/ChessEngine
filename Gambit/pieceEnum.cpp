//
// Created by Dan on 11/15/2017.
//

#include "Enums.h"

std::string pieceEnum::pieceToString(int id) {
    static const char* pieceStrings[] = {"Pawn", "Knight", "Bishop", "Rook", "Queen", "King", "PIECE_DEFAULT"};
    return pieceStrings[id];
}

