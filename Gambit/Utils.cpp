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
        case 'D':
        case 'd':
            return BLACK;
        default:
            return COLOR_DEFAULT;
    }
}

bool Utils::combineBoards(std::vector<Board*> allBoards, Board* mainBoard) {
    mainBoard->board = 0;
    for (Board* board : allBoards) {
        mainBoard->board |= board->board;
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

int Utils::getPieceLocation(std::string rank, std::string file) {
    int a = 1;
    int b = a + 1;
    int c = b + 1;
    int d = c + 1;
    int e = d + 1;
    int f = e + 1;
    int g = f + 1;
    int h = g + 1;

    int localRank = 0;
    int localFile = 0;

    if (rank == "A" || rank == "a") localRank = a;
    if (rank == "B" || rank == "b") localRank = b;
    if (rank == "C" || rank == "c") localRank = c;
    if (rank == "D" || rank == "d") localRank = d;
    if (rank == "E" || rank == "e") localRank = e;
    if (rank == "F" || rank == "f") localRank = f;
    if (rank == "G" || rank == "g") localRank = g;
    if (rank == "H" || rank == "h") localRank = h;

    if (file == "1") localFile = 1;
    if (file == "2") localFile = 2;
    if (file == "3") localFile = 3;
    if (file == "4") localFile = 4;
    if (file == "5") localFile = 5;
    if (file == "6") localFile = 6;
    if (file == "7") localFile = 7;
    if (file == "8") localFile = 8;

    int location = (localRank - (8 * (localFile - 1)));

    return location;
}
