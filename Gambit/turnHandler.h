//
// Created by Dan on 12/3/2017.
//

#ifndef GAMBIT_TURNHANDLER_H
#define GAMBIT_TURNHANDLER_H


#include "Enums.h"

class turnHandler {
public:
    turnHandler();
    color  getCurrentTurn();
    bool changeTurn();

private:
    color currentTurn;

};


#endif //GAMBIT_TURNHANDLER_H
