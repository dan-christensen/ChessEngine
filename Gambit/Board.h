//
// Created by Dan on 11/8/2017.
//

#ifndef GAMBIT_BOARD_H
#define GAMBIT_BOARD_H

#include "Enums.h"

#include <bitset>
#include <vector>


class Board {
public:
    Enums::Piece boardType;
    Enums::Color boardColor;

    unsigned long long board;
    unsigned long long bitMask;
    std::bitset<64> bitBoard;

    Board();
    Board(Enums::Color boardColor,Enums::Piece boardType, unsigned long long boardValue);
    bool setBitBoard();
    bool setBitMask();
    bool placePiece(std::string rank, std::string file);

};


#endif //GAMBIT_BOARD_H
