//
// Created by Dan on 11/10/2017.
//

#ifndef GAMBIT_PLACEMENT_H
#define GAMBIT_PLACEMENT_H

#include "Board.h"

#include <vector>

class Placement {
public:
    bool placePiece(Board* board, std::string rank, std::string file);
    bool combineBoards(std::vector<Board*>* allBoards, Board* mainBoard);
};


#endif //GAMBIT_PLACEMENT_H
