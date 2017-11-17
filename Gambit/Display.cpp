//
// Created by Dan on 11/9/2017.
//

#include "Display.h"

bool Display::DrawBoard(Board *board) {
    int index = 7;
    char file = 'H';

    for (int j = 0; j < 8; ++j) {
        std::cout << file-- << " ";
        for (int i = index; i > index - 8; --i) {
            if (board->bitBoard[i]) {
                std::cout << 1 << " ";
            } else {
                std::cout << ". ";
            }
        }
        index += 8;
        std::cout << std::endl;
    }
    std::cout << "  1 2 3 4 5 6 7 8" << std::endl;
    std::cout << std::endl;

    return true;
}

bool Display::DrawBoard(std::vector<Board *> allBoards) {
    char token = '-';
    for (Board *board : allBoards) {
        switch (board->boardType) {

            case PAWN:
                token = 'P';
                break;
            case KNIGHT:
                token = 'N';
                break;
            case BISHOP:
                token = 'B';
                break;
            case ROOK:
                token = 'R';
                break;
            case QUEEN:
                token = 'Q';
                break;
            case KING:
                token = 'K';
                break;
        }

    }

    return true;
}
