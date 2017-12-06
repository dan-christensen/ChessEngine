//
// Created by Dan on 11/15/2017.
//

#include "utils.h"

piece utils::getPiece(char pieceToken) {
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

color utils::getColor(char colorToken) {
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

bool utils::combineBoards(std::vector<board*> allBoards, board* mainBoard) {
    mainBoard->b = 0;
    for (board* board : allBoards) {
        mainBoard->b |= board->b;
    }
    mainBoard->setBitBoard();
    return true;
}

board* utils::getBoard(std::vector<board*> allBoards, color color, piece piece) {
    for (auto&& board : allBoards) {
        if (board->boardColor == color && board->boardType == piece) {
            return board;
        }
    }

    return nullptr;
}

int utils::getPieceLocation(std::string rank, std::string file) {
    int a = 0;
    int b = a + 1;
    int c = a + 2;
    int d = a + 3;
    int e = a + 4;
    int f = a + 5;
    int g = a + 6;
    int h = a + 7;

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

//    int location = (localRank - (8 * (localFile - 1)));

    // i = x + (width * y)
    // x = rank (A-H)
    int location = localRank + (8 * (localFile - 1));

    return location;
}

bool utils::isSpaceClear(int position, unsigned long long board) {
    unsigned long long flag = 0;
    flag |= 1Ull << position;

    return (board & flag) == 0;
}
