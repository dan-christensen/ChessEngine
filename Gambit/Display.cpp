//
// Created by Dan on 11/9/2017.
//

#include "Display.h"

Display::Display() {
    VERTICAL_BAR = "\u2502";
    VERTICAL_BAR_BOARDER = "\u2551";

    VERTICAL_BAR_LEFT = "\u2525";
    VERTICAL_BAR_BOARDER_LEFT = "\u2562";

    VERTICAL_BAR_RIGHT = "\u2523";
    VERTICAL_BAR_BOARDER_RIGHT = "\u255F";

    HORIZONTAL_BAR = "\u2500";
    HORIZONTAL_BAR_BOARDER = "\u2550";

    HORIZONTAL_BAR_UP = "\u253B";
    HORIZONTAL_BAR_BOARDER_UP = "\u2567";

    HORIZONTAL_BAR_DOWN = "\u2533";
    HORIZONTAL_BAR_BOARDER_DOWN = "\u2564";

    TOP_RIGHT_CORNER = "\u250F";
    TOP_RIGHT_CORNER_BOARDER = "\u2554";

    TOP_LEFT_CORNER = "\u2513";
    TOP_LEFT_CORNER_BOARDER = "\u2557";

    BOTTOM_RIGHT_CORNER = "\u2517";
    BOTTOM_RIGHT_CORNER_BOARDER = "\u255A";

    BOTTOM_LEFT_CORNER = "\u251B";
    BOTTOM_LEFT_CORNER_BOARDER = "\u255D";

    INTERSECTION;
}

bool Display::DrawBoard(Board *board) {
    int index = 7;
    char file = 'H';

    std::cout << "  " << TOP_RIGHT_CORNER_BOARDER;
    for (int k = 0; k < 15; ++k) {
        std::cout << HORIZONTAL_BAR_BOARDER_DOWN;
    }
    std::cout << TOP_LEFT_CORNER_BOARDER << std::endl;
    for (int j = 0; j < 8; ++j) {
        std::cout << file-- << " ";
        std::cout << VERTICAL_BAR_BOARDER;
        for (int i = index; i > index - 8; --i) {
            if (board->bitBoard[i]) {
                std::cout << 1;
            } else {
                std::cout << " ";
            }
            std::cout << VERTICAL_BAR;
        }
        index += 8;
        std::cout << std::endl;
    }
    std::cout << "  " << BOTTOM_RIGHT_CORNER_BOARDER;
    for (int k = 0; k < 15; ++k) {
        std::cout << HORIZONTAL_BAR_BOARDER_UP;
    }
    std::cout << BOTTOM_LEFT_CORNER_BOARDER << std::endl;
    std::cout << "  1 2 3 4 5 6 7 8" << std::endl;

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

