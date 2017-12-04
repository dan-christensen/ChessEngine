//
// Created by Dan on 12/3/2017.
//

#ifndef GAMBIT_TURNHANDLER_H
#define GAMBIT_TURNHANDLER_H


#include "Gambit/Enums.h"

class TurnHandler {
public:
    TurnHandler();
    Color  getCurrentTurn();
    bool changeTurn();

private:
    Color currentTurn;

};


#endif //GAMBIT_TURNHANDLER_H
