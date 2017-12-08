//
// Created by Dan on 11/14/2017.
//

#include "FileIO.h"

bool FileIO::parseFile(std::string move, std::vector<Board*> allBoards, Board* mainBoard, TurnHandler* turn) {
    std::string input = move;
    for (auto& c: input) c = toupper(c);

    std::regex placementPattern("([KQBNRP])([DL])(([A-H])([1-8]))");
    std::regex movementPattern("(([A-H])([1-8])([A-H])([1-8]))\\*?");

    if (std::regex_match(input, placementPattern)) {
        return parsePlacement(input, allBoards, mainBoard, turn);
    } else if (std::regex_match(input, movementPattern)) {
        return paresMove(input, allBoards, mainBoard, turn);
    } else {
        std::cout << "ERROR: Invalid input." << std::endl;
        return false;
    }

    return false;
}

bool FileIO::parsePlacement(std::string move, std::vector<Board*> allBoards, Board* mainBoard, TurnHandler* turn) {
    return placement->placePiece(move, allBoards, mainBoard, turn);
}

bool FileIO::paresMove(std::string move, std::vector<Board*> allBoards, Board* mainBoard, TurnHandler* turn) {
    return movement->movePiece(move, allBoards, mainBoard, turn);
}

std::string FileIO::getUserInput() {
    std::string rVal;
    std::cout << "Please enter a move: ";
    std::cin >> rVal;
    std::cout << std::endl;
    return rVal;
}
