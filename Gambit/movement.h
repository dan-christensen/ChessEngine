//
// Created by Dan on 11/15/2017.
//

#ifndef GAMBIT_MOVEMENT_H
#define GAMBIT_MOVEMENT_H


#include "board.h"
#include "turnHandler.h"

class movement {
public:
    bool movePiece(std::string move, std::vector<board*> allBoards, board* mainBoard, turnHandler* turn);
};


#endif //GAMBIT_MOVEMENT_H
