#include "Board.h"
#include "Enums.h"
#include "Display.h"
#include "Placement.h"
#include "FileIO.h"

#include <iostream>
#include <bitset>
#include <vector>

int main() {
    Placement placement;

    Board* mainBoard = new Board(Enums::COLOR_DEFAULT, Enums::PIECE_DEFAULT, 0);

    Board* whitePawnBoard = new Board(Enums::WHITE, Enums::PAWN, 0);
    Board* whiteKnightBoard = new Board(Enums::WHITE, Enums::KNIGHT, 0);
    Board* whiteBishopBoard = new Board(Enums::WHITE, Enums::BISHOP, 0);
    Board* whiteRookBoard = new Board(Enums::WHITE, Enums::ROOK, 0);
    Board* whiteQueenBoard = new Board(Enums::WHITE, Enums::QUEEN, 0);
    Board* whiteKingBoard = new Board(Enums::WHITE, Enums::KING, 0);

    Board* blackPawnBoard = new Board(Enums::BLACK, Enums::PAWN, 0);
    Board* blackKnightBoard = new Board(Enums::BLACK, Enums::KNIGHT, 0);
    Board* blackBishopBoard = new Board(Enums::BLACK, Enums::BISHOP, 0);
    Board* blackRookBoard = new Board(Enums::BLACK, Enums::ROOK, 0);
    Board* blackQueenBoard = new Board(Enums::BLACK, Enums::QUEEN, 0);
    Board* blackKingBoard = new Board(Enums::BLACK, Enums::KING, 0);

    std::vector<Board*> allBoards;
    allBoards.push_back(whitePawnBoard);
    allBoards.push_back(whiteKnightBoard);
    allBoards.push_back(whiteBishopBoard);
    allBoards.push_back(whiteRookBoard);
    allBoards.push_back(whiteQueenBoard);
    allBoards.push_back(whiteKingBoard);

    allBoards.push_back(blackPawnBoard);
    allBoards.push_back(blackKnightBoard);
    allBoards.push_back(blackBishopBoard);
    allBoards.push_back(blackRookBoard);
    allBoards.push_back(blackQueenBoard);
    allBoards.push_back(blackKingBoard);

//    placement.placePiece(mainBoard, "H", "8");
//    placement.placePiece(mainBoard, "d", "4");
//    placement.placePiece(mainBoard, "e", "a");
//    placement.placePiece(mainBoard, "f", "2");


//    std::cout << mainBoard->bitBoard << std::endl;
//    std::cout << mainBoard->board << std::endl;

    FileIO file;
    file.parseFile("PLA1", &allBoards, mainBoard);
    file.parseFile("NLA3", &allBoards, mainBoard);
    file.parseFile("qdf4", &allBoards, mainBoard);

    Display display;
//    display.DrawBoard(whitePawnBoard);
//    display.DrawBoard(whiteKnightBoard);
//    display.DrawBoard(blackQueenBoard);
    display.DrawBoard(mainBoard);

    return 0;
}