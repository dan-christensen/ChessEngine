//
// Created by Dan on 11/10/2017.
//

#ifndef GAMBIT_PLACEMENT_H
#define GAMBIT_PLACEMENT_H

#include "Board.h"
#include "TurnHandler.h"

#include <vector>

class Placement {
public:
    bool placePiece(std::string move, std::vector<Board*> allBoards, Board* mainBoard, TurnHandler* turn);
};


#endif //GAMBIT_PLACEMENT_H
