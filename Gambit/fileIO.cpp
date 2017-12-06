//
// Created by Dan on 11/14/2017.
//

#include "fileIO.h"

bool fileIO::parseFile(std::string move, std::vector<board*> allBoards, board* mainBoard, turnHandler* turn) {
    std::string input = move;
    for (auto& c: input) c = toupper(c);

    std::regex placementPattern("([KQBNRP])([DL])(([A-H])([1-8]))");
    std::regex movementPattern("(([A-H])([1-8])([A-H])([1-8]))\\*?");

    if (std::regex_match(input, placementPattern)) {
        return parsePlacement(input, allBoards, mainBoard, turn);
    } else if (std::regex_match(input, movementPattern)) {
        return paresMove(input, allBoards, mainBoard, turn);
    }

    return true;
}

bool fileIO::parsePlacement(std::string move, std::vector<board*> allBoards, board* mainBoard, turnHandler* turn) {
    return placement->placePiece(move, allBoards, mainBoard, turn);
}

bool fileIO::paresMove(std::string move, std::vector<board*> allBoards, board* mainBoard, turnHandler* turn) {
    return movement->movePiece(move, allBoards, mainBoard, turn);
}

std::string fileIO::getUserInput() {
    std::string rVal;
    std::cout <<  "Please enter a move: ";
    std::cin >> rVal;
    std::cout << std::endl;
    return rVal;
}
