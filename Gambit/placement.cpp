//
// Created by Dan on 11/10/2017.
//

#include "placement.h"
#include "utils.h"

bool placement::placePiece(std::string move, std::vector<board*> allBoards, board* mainBoard, turnHandler* turn) {
    piece piece = utils::getPiece(move[0]);
    color color = utils::getColor(move[1]);
    board* board = utils::getBoard(allBoards, color, piece);

    std::string rank = move.substr(2, 1);
    std::string file = move.substr(3);

    if (board == nullptr) {
        return false;
    }
//    if (turn.getCurrentTurn() != b->boardColor) {
//        return false;
//    }
    if (!utils::isSpaceClear(utils::getPieceLocation(rank, file), board->b)) {
        return false;
    }

    board->placePiece(rank, file);
    utils::combineBoards(allBoards, mainBoard);

    return true;
}

