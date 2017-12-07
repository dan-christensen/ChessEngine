//
// Created by Dan on 11/15/2017.
//

#include "Movement.h"
#include "Utils.h"

bool Movement::movePiece(std::string move, std::vector<Board*> allBoards, Board* mainBoard, TurnHandler* turn) {
    Board* tempBoard = new Board(COLOR_DEFAULT, PIECE_DEFAULT, 0);
    Board* moveBoard = nullptr;
    Piece piece = PIECE_DEFAULT;
    Color color = COLOR_DEFAULT;
    std::string startRank = move.substr(0, 1);
    std::string startFile = move.substr(1, 1);
    std::string endRank = move.substr(2, 1);
    std::string endFile = move.substr(3, 1);

    tempBoard->placePiece(startRank, startFile);

    for (Board* board : allBoards) {
        unsigned long long temp = tempBoard->board & board->board;
        if (tempBoard->board == temp) {
            moveBoard = board;
            piece = moveBoard->boardType;
            color = moveBoard->boardColor;
            break;
        }
    }

    if (moveBoard == nullptr) {
        return false;
    }
    if (moveBoard->boardColor != turn->getCurrentTurn()){
        return false;
    }

    moveBoard->movePiece(startRank, startFile, endRank, endFile);

    Utils::combineBoards(allBoards, mainBoard);
    return true;;
}
