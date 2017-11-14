//
// Created by Dan on 11/10/2017.
//

#include "Placement.h"

bool Placement::placePiece(Board* board, std::string rank, std::string file) {
    return board->placePiece(rank, file);
}

bool Placement::combineBoards(std::vector<Board*>* allBoards, Board* mainBoard) {
    for (Board* board : *allBoards) {
        mainBoard->board = mainBoard->board | board->board;
    }
    mainBoard->setBitBoard();
    return true;
}
