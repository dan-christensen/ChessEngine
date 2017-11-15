//
// Created by Dan on 11/14/2017.
//

#include "FileIO.h"

bool FileIO::parseFile(std::string move, std::vector<Board*> allBoards, Board* mainBoard) {
    std::string input = move;
    for (auto & c: input) c = toupper(c);

    std::regex placementPattern("([KQBNRP])([DL])(([A-H])([1-8]))");
    std::regex movementPattern("(([A-H])([1-8])([A-H])([1-8]))\\*?");

    if (std::regex_match(input, placementPattern)){
        parsePlacement(input, allBoards, mainBoard);
    }
    else if (std::regex_match(input, movementPattern)) {
        paresMove(input, allBoards, mainBoard);
    }

    return true;
}

bool FileIO::parsePlacement(std::string move, std::vector<Board*> allBoards, Board* mainBoard) {
    Color color = COLOR_DEFAULT;
    Piece piece = PIECE_DEFAULT;
    Board* board = nullptr;

    switch (move[0]){
        case 'P':
            piece = PAWN;
            break;
        case 'N':
            piece = KNIGHT;
            break;
        case 'B':
            piece = BISHOP;
            break;
        case 'R':
            piece = ROOK;
            break;
        case 'Q':
            piece = QUEEN;
            break;
        case 'K':
            piece = KING;
            break;
        default:break;
    }

    switch (move[1]){
        case 'L':
            color = WHITE;
            break;
        case 'D':
            color = BLACK;
            break;
        default:break;
    }

    for (Board* b : allBoards){
        if (b->boardType == piece && b->boardColor == color){
            board = b;
        }
    }

    if (board == nullptr){
        return false;
    }

    std::string rank = move.substr(2, 1);
    std::string file = move.substr(3);

    placement->placePiece(board, rank, file);
    placement->combineBoards(allBoards, mainBoard);

    return true;
}

bool FileIO::paresMove(std::string move, std::vector<Board*> allBoards, Board* mainBoard) {
    Board* tempBoard = new Board(COLOR_DEFAULT, PIECE_DEFAULT, 0);
    Piece piece;
    Color color;
    std::string startRank = move.substr(0, 1);
    std::string startFile = move.substr(1, 1);
    std::string endRank = move.substr(2, 1);
    std::string endFile = move.substr(3, 1);
    std::cout << startRank << std::endl;
    std::cout << startFile << std::endl;
    std::cout << endRank << std::endl;
    std::cout << endFile << std::endl;

    tempBoard->placePiece(startRank, startFile);
    std::cout << tempBoard->bitBoard << std::endl;

    return false;
}
