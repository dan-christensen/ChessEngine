//
// Created by Dan on 12/6/2017.
//

#ifndef GAMBIT_GAMEHANDLER_H
#define GAMBIT_GAMEHANDLER_H


#include "Board.h"
#include "Display.h"
#include "FileIO.h"

class GameHandler {
public:
    bool init();
    bool draw();
    bool update();

    Board* mainBoard;
    Board* whitePawnBoard;
    Board* whiteKnightBoard;
    Board* whiteBishopBoard;
    Board* whiteRookBoard;
    Board* whiteQueenBoard;
    Board* whiteKingBoard;

    Board* blackPawnBoard;
    Board* blackKnightBoard;
    Board* blackBishopBoard;
    Board* blackRookBoard;
    Board* blackQueenBoard;
    Board* blackKingBoard;

    std::vector<Board*> allBoards;
    std::vector<Board*> allWhiteBoards;
    std::vector<Board*> allBlackBoards;

    Board* whiteBoard;
    Board* blackBoard;

private:
    Display screen;
    FileIO file;
    TurnHandler* turn;
};


#endif //GAMBIT_GAMEHANDLER_H
