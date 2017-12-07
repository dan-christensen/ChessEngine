//
// Created by Dan on 11/14/2017.
//

#ifndef GAMBIT_FILEIO_H
#define GAMBIT_FILEIO_H


#include "enums.h"
#include "board.h"
#include "placement.h"
#include "utils.h"
#include "movement.h"
#include "turnHandler.h"

#include <string>
#include <regex>
#include <iostream>
#include <vector>

class fileIO {
public:
    bool parseFile(std::string move, std::vector<board*> allBoards, board* mainBoard, turnHandler* turn);
    std::string getUserInput();

private:
    bool parsePlacement(std::string move, std::vector<board*> allBoards, board* mainBoard, turnHandler* turn);
    bool paresMove(std::string move, std::vector<board*> allBoards, board* mainBoard, turnHandler* turn);

    placement* placement;
    movement* movement;

};


#endif //GAMBIT_FILEIO_H
