//
// Created by Dan on 11/15/2017.
//

#include "Utils.h"

Piece Utils::getPiece(char pieceToken) {
    switch (pieceToken) {
        case 'P':
        case 'p':
            return PAWN;
        case 'N':
        case 'n':
            return KNIGHT;
        case 'B':
        case 'b':
            return BISHOP;
        case 'R':
        case 'r':
            return ROOK;
        case 'Q':
        case 'q':
            return QUEEN;
        case 'K':
        case 'k':
            return KING;
        default:
            return PIECE_DEFAULT;

    }
}

Color Utils::getColor(char colorToken) {
    switch (colorToken) {
        case 'L':
        case 'l':
            return WHITE;
        case 'B':
        case 'b':
            return BLACK;
        default:
            return COLOR_DEFAULT;
    }
}

bool Utils::combineBoards(std::vector<Board*> allBoards, Board* mainBoard) {
    for (Board* board : allBoards) {
        mainBoard->board = mainBoard->board | board->board;
    }
    mainBoard->setBitBoard();
    return true;
}

Board* Utils::getBoard(std::vector<Board*> allBoards, Color color, Piece piece) {
    for (auto&& board : allBoards) {
        if (board->boardColor == color && board->boardType == piece) {
            return board;
        }
    }

    return nullptr;
}
