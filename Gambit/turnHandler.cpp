//
// Created by Dan on 12/3/2017.
//

#include "turnHandler.h"

turnHandler::turnHandler() {
    this->currentTurn = WHITE;
}

color turnHandler::getCurrentTurn() {
    return currentTurn;
}

bool turnHandler::changeTurn() {
    if (currentTurn == WHITE) {
        currentTurn = BLACK;
    } else if (currentTurn == BLACK) {
        currentTurn = WHITE;
    }

    return true;
}
