#include "Board.h"
#include "Enums.h"
#include "Display.h"
#include "Placement.h"

#include <iostream>
#include <bitset>
#include <vector>

int main() {
    Placement placement;

    Board *mainBoard = new Board();
    Board *whitePawnBoard = new Board(Enums::WHITE, Enums::PAWN,
                                      0b0000000011111111000000000000000000000000000000000000000000000000);
    Board *whiteKnightBoard = new Board(Enums::WHITE, Enums::KNIGHT,
                                        0b0100001000000000000000000000000000000000000000000000000000000000);
    Board *whiteBishopBoard = new Board(Enums::WHITE, Enums::BISHOP,
                                        0b0010010000000000000000000000000000000000000000000000000000000000);
    Board *whiteRookBoard = new Board(Enums::WHITE, Enums::ROOK,
                                      0b1000000100000000000000000000000000000000000000000000000000000000);
    Board *whiteQueenBoard = new Board(Enums::WHITE, Enums::QUEEN,
                                       0b0001000000000000000000000000000000000000000000000000000000000000);
    Board *whiteKingBoard = new Board(Enums::WHITE, Enums::KING,
                                      0b0000100000000000000000000000000000000000000000000000000000000000);

    Board *blackPawnBoard = new Board(Enums::BLACK, Enums::PAWN,
                                      0b0000000000000000000000000000000000000000000000001111111100000000);
    Board *blackKnightBoard = new Board(Enums::BLACK, Enums::KNIGHT,
                                        0b00000000000000000000000000000000000000000000000000000000001000010);
    Board *blackBishopBoard = new Board(Enums::BLACK, Enums::BISHOP,
                                        0b0000000000000000000000000000000000000000000000000000000000100100);
    Board *blackRookBoard = new Board(Enums::BLACK, Enums::ROOK,
                                      0b0000000000000000000000000000000000000000000000000000000010000001);
    Board *blackQueenBoard = new Board(Enums::BLACK, Enums::QUEEN,
                                       0b0000000000000000000000000000000000000000000000000000000000010000);
    Board *blackKingBoard = new Board(Enums::BLACK, Enums::KING,
                                      0b0000000000000000000000000000000000000000000000000000000000001000);

    std::vector<Board *> allBoards;
//    allBoards.push_back(whitePawnBoard);
//    allBoards.push_back(whiteKnightBoard);
//    allBoards.push_back(whiteBishopBoard);
//    allBoards.push_back(whiteRookBoard);
//    allBoards.push_back(whiteQueenBoard);
//    allBoards.push_back(whiteKingBoard);
//
//    allBoards.push_back(blackPawnBoard);
//    allBoards.push_back(blackKnightBoard);
//    allBoards.push_back(blackBishopBoard);
//    allBoards.push_back(blackRookBoard);
//    allBoards.push_back(blackQueenBoard);
//    allBoards.push_back(blackKingBoard);

    for (Board *board : allBoards) {
        mainBoard->board = mainBoard->board | board->board;
    }

    placement.placePiece(mainBoard, "H", "8");
    placement.placePiece(mainBoard, "d", "4");
    placement.placePiece(mainBoard, "e", "a");
    placement.placePiece(mainBoard, "f", "2");

//    std::cout << mainBoard->bitBoard << std::endl;
//    std::cout << mainBoard->board << std::endl;

    Display display;
    display.DrawBoard(mainBoard);

    return 0;
}