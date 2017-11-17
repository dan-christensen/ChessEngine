//
// Created by Dan on 11/14/2017.
//

#include "FileIO.h"

bool FileIO::parseFile(std::string move, std::vector<Board*> allBoards, Board* mainBoard) {
    std::string input = move;
    for (auto& c: input) c = toupper(c);

    std::regex placementPattern("([KQBNRP])([DL])(([A-H])([1-8]))");
    std::regex movementPattern("(([A-H])([1-8])([A-H])([1-8]))\\*?");

    if (std::regex_match(input, placementPattern)) {
        parsePlacement(input, allBoards, mainBoard);
    } else if (std::regex_match(input, movementPattern)) {
        paresMove(input, allBoards, mainBoard);
    }

    return true;
}

bool FileIO::parsePlacement(std::string move, std::vector<Board*> allBoards, Board* mainBoard) {
    Piece piece = Utils::getPiece(move[0]);
    Color color = Utils::getColor(move[1]);
    Board* board = Utils::getBoard(allBoards, color, piece);

    if (board == nullptr) {
        return false;
    }

    std::string rank = move.substr(2, 1);
    std::string file = move.substr(3);

    placement->placePiece(board, rank, file);
    Utils::combineBoards(allBoards, mainBoard);

    return true;
}

bool FileIO::paresMove(std::string move, std::vector<Board*> allBoards, Board* mainBoard) {
    Board* tempBoard = new Board(COLOR_DEFAULT, PIECE_DEFAULT, 0);
    Board* moveBoard = nullptr;
    Piece piece = PIECE_DEFAULT;
    Color color = COLOR_DEFAULT;
    std::string startRank = move.substr(0, 1);
    std::string startFile = move.substr(1, 1);
    std::string endRank = move.substr(2, 1);
    std::string endFile = move.substr(3, 1);

    tempBoard->placePiece(startRank, startFile);

    for (Board* board : allBoards) {
        unsigned long long temp = tempBoard->board & board->board;
        if (tempBoard->board == temp) {
            moveBoard = board;
            piece = moveBoard->boardType;
            color = moveBoard->boardColor;
            break;
        }
    }

    if (moveBoard == nullptr) {
        return false;
    }

    moveBoard->movePiece(startRank, startFile, endRank, endFile);

    Utils::combineBoards(allBoards, mainBoard);
    return true;
}
