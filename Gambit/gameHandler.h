//
// Created by Dan on 12/6/2017.
//

#ifndef GAMBIT_GAMEHANDLER_H
#define GAMBIT_GAMEHANDLER_H


#include "board.h"
#include "display.h"
#include "fileIO.h"

class gameHandler {
public:
    bool init();
    bool draw();
    bool update();

    board *mainBoard;
    board *whitePawnBoard;
    board *whiteKnightBoard;
    board *whiteBishopBoard;
    board *whiteRookBoard;
    board *whiteQueenBoard;
    board *whiteKingBoard;
    board *blackPawnBoard;
    board *blackKnightBoard;
    board *blackBishopBoard;
    board *blackRookBoard;
    board *blackQueenBoard;
    board *blackKingBoard;

    std::vector<board*> allBoards;

private:
    display display;
    fileIO file;
    turnHandler* turn;
};


#endif //GAMBIT_GAMEHANDLER_H
