//
// Created by Dan on 11/9/2017.
//
#include <vector>

#include "display.h"
#include "TermColor/termcolor.hpp"


display::display() {
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

bool display::drawBoard(unsigned long long board) {
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

bool display::drawBoard(std::vector<board*> allBoards) {

    std::vector<Square*> boardToDraw;
    std::string r = "A";
    std::string f = "1";
    for (int i = 0; i < 64; ++i) {
        boardToDraw.push_back(new Square(r, f));
        ++r[0];
        if (r[0] > 'H') {
            r[0] = 'A';
            ++f[0];
        }
    }

    for (board* board : allBoards) {
        for (int i = 0; i < 64; ++i) {
            if (board->bitBoard[i]) {
                boardToDraw[i]->token = getPieceToken(board->boardColor, board->boardType);
            }
        }
    }

    int index = 64;
    std::cout << "  " << TOP_RIGHT_CORNER_BOARDER;
    for (int l = 0; l < 7; ++l) {
        std::cout << HORIZONTAL_BAR_BOARDER << HORIZONTAL_BAR_BOARDER << HORIZONTAL_BAR_BOARDER
                  << HORIZONTAL_BAR_BOARDER_DOWN;
    }
    std::cout << HORIZONTAL_BAR_BOARDER << HORIZONTAL_BAR_BOARDER << HORIZONTAL_BAR_BOARDER << TOP_LEFT_CORNER_BOARDER
              << std::endl;

    char file = '8';
    for (int k = 0; k < 8; ++k) {
        if (k != 0) {
            std::cout << "  " << VERTICAL_BAR_BOARDER_RIGHT;
            for (int i = 0; i < 7; ++i) {
                std::cout << HORIZONTAL_BAR << HORIZONTAL_BAR << HORIZONTAL_BAR << INTERSECTION;
            }
            std::cout << HORIZONTAL_BAR << HORIZONTAL_BAR << HORIZONTAL_BAR << VERTICAL_BAR_BOARDER_LEFT << std::endl;
        }
        std::cout << " " << file-- << VERTICAL_BAR_BOARDER;
        for (int j = index - 8; j < index; ++j) {
            std::cout << " " << boardToDraw[j]->token << " ";
            if (j == index - 1) {
                std::cout << VERTICAL_BAR_BOARDER;
            } else {
                std::cout << VERTICAL_BAR;
            }
        }
        std::cout << std::endl;
        index -= 8;
    }
    std::cout << "  " << BOTTOM_RIGHT_CORNER_BOARDER;
    for (int l = 0; l < 7; ++l) {
        std::cout << HORIZONTAL_BAR_BOARDER << HORIZONTAL_BAR_BOARDER << HORIZONTAL_BAR_BOARDER
                  << HORIZONTAL_BAR_BOARDER_UP;
    }
    std::cout << HORIZONTAL_BAR_BOARDER << HORIZONTAL_BAR_BOARDER << HORIZONTAL_BAR_BOARDER
              << BOTTOM_LEFT_CORNER_BOARDER << std::endl;
    std::cout << "    A   B   C   D   E   F   G    H" << std::endl;

    return true;
}

std::string display::getPieceToken(color color, piece piece) {
    switch (piece) {
        case PAWN:
            switch (color) {
                case WHITE:
                    return "\u2659";
                case BLACK:
                    return "\u265F";
            }
        case KNIGHT:
            switch (color) {
                case WHITE:
                    return "\u2658";
                case BLACK:
                    return "\u265E";
            }
        case BISHOP:
            switch (color) {
                case WHITE:
                    return "\u2657";
                case BLACK:
                    return "\u265D";
            }
        case ROOK:
            switch (color) {
                case WHITE:
                    return "\u2656";
                case BLACK:
                    return "\u265C";
            }
        case QUEEN:
            switch (color) {
                case WHITE:
                    return "\u2655";
                case BLACK:
                    return "\u265B";
            }
        case KING:
            switch (color) {
                case WHITE:
                    return "\u2654";
                case BLACK:
                    return "\u265A";
            }
    }
    return std::string();
}

display::Square::Square(std::string rank, std::string file, std::string token) {
    this->token = token;
    this->rank = rank;
    this->file = file;
}
