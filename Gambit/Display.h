//
// Created by Dan on 11/9/2017.
//

#ifndef GAMBIT_DISPLAY_H
#define GAMBIT_DISPLAY_H


#include <vector>
#include <iostream>

#include "Board.h"
#include "Enums.h"


class Display {
public:
    Display();
    bool drawBoard(unsigned long long board);
    bool drawBoard(std::vector<Board*> allBoards);

private:
    class Square {
    public:
        Square(std::string rank, std::string file, std::string token = "-");

        std::string token;
        std::string rank;
        std::string file;
    };

    std::string getPieceToken(Color color, Piece piece);

    std::string VERTICAL_BAR;
    std::string VERTICAL_BAR_BOARDER;

    std::string VERTICAL_BAR_LEFT;
    std::string VERTICAL_BAR_BOARDER_LEFT;

    std::string VERTICAL_BAR_RIGHT;
    std::string VERTICAL_BAR_BOARDER_RIGHT;

    std::string HORIZONTAL_BAR;
    std::string HORIZONTAL_BAR_BOARDER;

    std::string HORIZONTAL_BAR_UP;
    std::string HORIZONTAL_BAR_BOARDER_UP;

    std::string HORIZONTAL_BAR_DOWN;
    std::string HORIZONTAL_BAR_BOARDER_DOWN;

    std::string TOP_RIGHT_CORNER;
    std::string TOP_RIGHT_CORNER_BOARDER;

    std::string TOP_LEFT_CORNER;
    std::string TOP_LEFT_CORNER_BOARDER;

    std::string BOTTOM_RIGHT_CORNER;
    std::string BOTTOM_RIGHT_CORNER_BOARDER;

    std::string BOTTOM_LEFT_CORNER;
    std::string BOTTOM_LEFT_CORNER_BOARDER;

    std::string INTERSECTION;

};


#endif //GAMBIT_DISPLAY_H
