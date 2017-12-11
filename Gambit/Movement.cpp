//
// Created by Dan on 11/15/2017.
//

#include "Movement.h"
#include "Utils.h"
#include "M42/m42.h"

bool Movement::movePiece(std::string move, std::vector<Board*> allBoards, Board* mainBoard, TurnHandler* turn) {
    Board* startBoard = new Board(COLOR_DEFAULT, PIECE_DEFAULT, 0);
    Piece startPiece = PIECE_DEFAULT;
    Color startColor = COLOR_DEFAULT;

    Board* endBoard = new Board(COLOR_DEFAULT, PIECE_DEFAULT, 0);
    Piece endPiece = PIECE_DEFAULT;
    Color endColor = COLOR_DEFAULT;

//    Board* moveBoard = nullptr;
    std::string startRank = move.substr(0, 1);
    std::string startFile = move.substr(1, 1);
    std::string endRank = move.substr(2, 1);
    std::string endFile = move.substr(3, 1);

    startBoard->placePiece(startRank, startFile);
    endBoard->placePiece(endRank, endFile);

    for (Board* board : allBoards) {
        unsigned long long tempStart = startBoard->board & board->board;
        if (startBoard->board == tempStart) {
            startBoard = board;
            startPiece = startBoard->boardType;
            startColor = startBoard->boardColor;
        }
        unsigned long long tempEnd = endBoard->board & board->board;
        if (endBoard->board == tempEnd) {
            endBoard = board;
            endPiece = endBoard->boardType;
            endColor = endBoard->boardColor;
        }
    }

    startBoard->setBitMask(mainBoard, startRank, startFile);
    endBoard->setBitMask(mainBoard, endRank, endFile);

    if (startBoard->boardColor == COLOR_DEFAULT) {
        return false;
    }
    if (startBoard->boardColor != turn->getCurrentTurn()) {
        return false;
    }
    if (startColor == endColor) {
        return false;
    }
    if (startBoard->bitMask & endBoard->board) {

    }

    if (startColor != endColor) {
        endBoard->removePiece(endRank, endFile);
        startBoard->movePiece(startRank, startFile, endRank, endFile);
    } else {
        startBoard->movePiece(startRank, startFile, endRank, endFile);
    }

    Utils::combineBoards(allBoards, mainBoard);
    return true;;
}
