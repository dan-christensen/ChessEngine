//
// Created by Dan on 11/15/2017.
//

#ifndef GAMBIT_MOVEMENT_H
#define GAMBIT_MOVEMENT_H


#include "Board.h"
#include "TurnHandler.h"

class Movement {
public:
    bool movePiece(std::string move, std::vector<Board*> allBoards, Board* mainBoard, TurnHandler* turn);
};


#endif //GAMBIT_MOVEMENT_H
