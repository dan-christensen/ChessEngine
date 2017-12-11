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
    Piece boardType;
    Color boardColor;

    unsigned long long board;
    unsigned long long bitMask;
    std::bitset<64> bitBoard;

    Board();
    Board(Color boardColor, Piece boardType, unsigned long long boardValue);
    bool setBitBoard();
    bool setBitMask(Board* mainBoard, std::string rank, std::string file);
    bool placePiece(Board* mainBoard, std::string rank, std::string file);
    bool removePiece(std::string rank, std::string file);
    bool movePiece(Board* mainBoard, std::string startRank, std::string startFile, std::string endRank, std::string endFile);

};


#endif //GAMBIT_BOARD_H
