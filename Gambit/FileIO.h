//
// Created by Dan on 11/14/2017.
//

#ifndef GAMBIT_FILEIO_H
#define GAMBIT_FILEIO_H


#include "Enums.h"
#include "Board.h"
#include "Placement.h"
#include "Utils.h"
#include "Movement.h"
#include "TurnHandler.h"

#include <string>
#include <regex>
#include <iostream>
#include <vector>

class FileIO {
public:
    bool parseFile(std::string move, std::vector<Board*> allBoards, Board* mainBoard, TurnHandler* turn);
    std::string getUserInput();

private:
    bool parsePlacement(std::string move, std::vector<Board*> allBoards, Board* mainBoard, TurnHandler* turn);
    bool paresMove(std::string move, std::vector<Board*> allBoards, Board* mainBoard, TurnHandler* turn);

    Placement* placement;
    Movement* movement;

};


#endif //GAMBIT_FILEIO_H
