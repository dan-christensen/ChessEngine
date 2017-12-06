//
// Created by Dan on 11/15/2017.
//

#include "movement.h"
#include "utils.h"

bool movement::movePiece(std::string move, std::vector<board*> allBoards, board* mainBoard, turnHandler* turn) {
    board* tempBoard = new board(COLOR_DEFAULT, PIECE_DEFAULT, 0);
    board* moveBoard = nullptr;
    piece piece = PIECE_DEFAULT;
    color color = COLOR_DEFAULT;
    std::string startRank = move.substr(0, 1);
    std::string startFile = move.substr(1, 1);
    std::string endRank = move.substr(2, 1);
    std::string endFile = move.substr(3, 1);

    tempBoard->placePiece(startRank, startFile);

    for (board* board : allBoards) {
        unsigned long long temp = tempBoard->b & board->b;
        if (tempBoard->b == temp) {
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

    utils::combineBoards(allBoards, mainBoard);
    return true;;
}
