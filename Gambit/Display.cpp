//
// Created by Dan on 11/9/2017.
//

#include "Display.h"

#include <sstream>
#include <bitset>

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

    INTERSECTION = "\u253C";
}

bool Display::DrawBoard(unsigned long long board) {
    std::bitset<64> bitBoard = std::bitset<64>(board);

    int index = 7;
    int file = 8;

    std::cout << "  " << TOP_RIGHT_CORNER_BOARDER;
    for (int k = 0; k < 15; ++k) {
        if (k % 2 != 0) {
            std::cout << HORIZONTAL_BAR_BOARDER_DOWN;
        } else {
            std::cout << HORIZONTAL_BAR_BOARDER;
        }
    }
    std::cout << TOP_LEFT_CORNER_BOARDER << std::endl;
    for (int j = 0; j < 8; ++j) {
        std::cout << file-- << " ";
        std::cout << VERTICAL_BAR_BOARDER;
        for (int i = index; i > index - 8; --i) {
            if (bitBoard[i]) {
                std::cout << 1;
            } else {
                std::cout << " ";
            }
            if (i % 8 == 0) {
                std::cout << VERTICAL_BAR_BOARDER;
            } else {
                std::cout << VERTICAL_BAR;
            }
        }

        if (j < 7) {
            std::cout << std::endl << "  " << VERTICAL_BAR_BOARDER_RIGHT;
            for (int k = 0; k < 15; ++k) {
                if (k % 2 != 0) {
                    std::cout << INTERSECTION;
                } else {
                    std::cout << HORIZONTAL_BAR;
                }
            }
            std::cout << VERTICAL_BAR_BOARDER_LEFT;
        }
        index += 8;
        std::cout << std::endl;
    }
    std::cout << "  " << BOTTOM_RIGHT_CORNER_BOARDER;
    for (int k = 0; k < 15; ++k) {
        if (k % 2 != 0) {
            std::cout << HORIZONTAL_BAR_BOARDER_UP;
        } else {
            std::cout << HORIZONTAL_BAR_BOARDER;
        }
    }
    std::cout << BOTTOM_LEFT_CORNER_BOARDER << std::endl;
    std::cout << "   A B C D E F G H" << std::endl;

    return true;
}

bool Display::DrawBoard(std::vector<Board*> allBoards) {
    char token = '-';
    for (Board* board : allBoards) {
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

std::string Display::BitboardToString(uint64_t b1, uint64_t b2)
{
    std::ostringstream ss;
    for (int r = 7; r >= 0; --r) {
        ss << "    +---+---+---+---+---+---+---+---+    +---+---+---+---+---+---+---+---+\n";
        ss.width(3);
        ss << r + 1 << " |";
        for (int f = 0; f <= 7; ++f) {
            ss << ((b1 & (1ULL << ((r << 3) | f))) ? " X |" : "   |");
        }
        ss << "    |";
        for (int f = 0; f <= 7; ++f) {
            ss << ((b2 & (1ULL << ((r << 3) | f))) ? " X |" : "   |");
        }
        ss << '\n';
    }
    ss << "    +---+---+---+---+---+---+---+---+    +---+---+---+---+---+---+---+---+\n";
    ss << "      a   b   c   d   e   f   g   h        a   b   c   d   e   f   g   h  \n";
    return ss.str();
}


