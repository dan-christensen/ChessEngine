//
// Created by Dan on 11/10/2017.
//

#ifndef GAMBIT_PLACEMENT_H
#define GAMBIT_PLACEMENT_H

#include "board.h"
#include "turnHandler.h"

#include <vector>

class placement {
public:
    bool placePiece(std::string move, std::vector<board*> allBoards, board* mainBoard, turnHandler* turn);
};


#endif //GAMBIT_PLACEMENT_H
