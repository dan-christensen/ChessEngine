//
// Created by Dan on 11/14/2017.
//

#include "FileIO.h"

bool FileIO::parseFile(std::string move, std::vector<Board*>* allBoards, Board* mainBoard) {
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

bool FileIO::parsePlacement(std::string move, std::vector<Board*>* allBoards, Board* mainBoard) {
    Enums::Color color = Enums::COLOR_DEFAULT;
    Enums::Piece piece = Enums::PIECE_DEFAULT;
    Board* board = nullptr;

    switch (move[0]){
        case 'P':
            piece = Enums::PAWN;
            break;
        case 'N':
            piece = Enums::KNIGHT;
            break;
        case 'B':
            piece = Enums::BISHOP;
            break;
        case 'R':
            piece = Enums::ROOK;
            break;
        case 'Q':
            piece = Enums::QUEEN;
            break;
        case 'K':
            piece = Enums::KING;
            break;
        default:break;
    }

    switch (move[1]){
        case 'L':
            color = Enums::WHITE;
            break;
        case 'D':
            color = Enums::BLACK;
            break;
        default:break;
    }

    for (Board* b : *allBoards){
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

bool FileIO::paresMove(std::string move, std::vector<Board*>* allBoards, Board* mainBoard) {
    return false;
}
