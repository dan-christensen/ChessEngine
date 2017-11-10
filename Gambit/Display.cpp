//
// Created by Dan on 11/9/2017.
//

#include "Display.h"

bool Display::DrawBoard(Board *board) {
    int index = 7;

    for (int j = 0; j < 8; ++j) {
        for (int i = index; i > index - 8; --i) {
            std::cout << board->bitBoard[i];
//            std::cout << " " << i;
        }
        index += 8;
        std::cout << std::endl;
    }

    return true;
}

bool Display::DrawBoard(std::vector<Board *> allBoards) {
    char token = '-';
    for (Board *board : allBoards) {
        switch (board->boardType) {

            case Enums::PAWN:
                token = 'P';
                break;
            case Enums::KNIGHT:
                token = 'N';
                break;
            case Enums::BISHOP:
                token = 'B';
                break;
            case Enums::ROOK:
                token = 'R';
                break;
            case Enums::QUEEN:
                token = 'Q';
                break;
            case Enums::KING:
                token = 'K';
                break;
        }

    }

    return true;
}
