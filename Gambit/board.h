//
// Created by Dan on 11/8/2017.
//

#ifndef GAMBIT_BOARD_H
#define GAMBIT_BOARD_H

#include "enums.h"

#include <bitset>
#include <vector>


class board {
public:
    piece boardType;
    color boardColor;

    unsigned long long b;
    unsigned long long bitMask;
    std::bitset<64> bitBoard;

    board();
    board(color boardColor, piece boardType, unsigned long long boardValue);
    bool setBitBoard();
    bool setBitMask(unsigned long long bitMask);
    bool placePiece(std::string rank, std::string file);
    bool removePiece(std::string rank, std::string file);
    bool movePiece(std::string startRank, std::string startFile, std::string endRank, std::string endFile);

};


#endif //GAMBIT_BOARD_H
