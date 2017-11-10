//
// Created by Dan on 11/9/2017.
//

#ifndef GAMBIT_DISPLAY_H
#define GAMBIT_DISPLAY_H


#include "Board.h"

#include <vector>

#include <iostream>

class Display {
public:
    bool DrawBoard(Board* board);
    bool DrawBoard(std::vector<Board*> allBoards);

};


#endif //GAMBIT_DISPLAY_H
