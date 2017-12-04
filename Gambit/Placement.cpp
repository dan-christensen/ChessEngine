//
// Created by Dan on 11/10/2017.
//

#include "Placement.h"
#include "Utils.h"

bool Placement::placePiece(std::string move, std::vector<Board*> allBoards, Board* mainBoard, TurnHandler* turn) {
    Piece piece = Utils::getPiece(move[0]);
    Color color = Utils::getColor(move[1]);
    Board* board = Utils::getBoard(allBoards, color, piece);

    std::string rank = move.substr(2, 1);
    std::string file = move.substr(3);

    if (board == nullptr) {
        return false;
    }
//    if (turn.getCurrentTurn() != board->boardColor) {
//        return false;
//    }
    if (!Utils::isSpaceClear(Utils::getPieceLocation(rank, file), board->board)) {
        return false;
    }

    board->placePiece(rank, file);
    Utils::combineBoards(allBoards, mainBoard);

    return true;
}

