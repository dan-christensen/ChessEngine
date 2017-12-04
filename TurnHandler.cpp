//
// Created by Dan on 12/3/2017.
//

#include "TurnHandler.h"

TurnHandler::TurnHandler() {
    this->currentTurn = WHITE;
}

Color TurnHandler::getCurrentTurn() {
    return currentTurn;
}

bool TurnHandler::changeTurn() {
    if (currentTurn == WHITE) {
        currentTurn = BLACK;
    } else if (currentTurn == BLACK) {
        currentTurn = WHITE;
    }

    return true;
}
