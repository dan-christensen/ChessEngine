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

bool Display::drawBoard(unsigned long long board) {
    std::bitset<64> bitboard = std::bitset<64>(board);

    int index = 63;

    for (int i = 0; i < 8; ++i) {
        for (int j = index - 7; j <= index; ++j) {
//            std::cout << bitboard[j] << " [" << j << "] ";
            if (bitboard[j]) {
               std::cout << "1";
            } else {
                std::cout << "-";
            }
        }
        std::cout << std::endl;
        index -= 8;
    }

    std::cout << std::endl;
    return true;
}

bool Display::drawBoard(std::vector<Board*> allBoards) {
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
            case PIECE_DEFAULT:
                token = '-';
                break;
        }

    }

    return true;
}

std::string Display::bitboardToString(uint64_t b1, uint64_t b2) {
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


