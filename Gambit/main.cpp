//todo(dan): flip the board so a1=0, a2=1...h8=63.
//todo(dan): finish movement check if space is available or if it is the opposite color.

#include "Board.h"
#include "Enums.h"
#include "Display.h"
#include "Placement.h"
#include "FileIO.h"
#include "M42/m42.h"

#include <iostream>
#include <bitset>
#include <vector>

int main() {
    M42::init();

    Placement placement;

    Board* mainBoard = new Board(COLOR_DEFAULT, PIECE_DEFAULT, 0);

    Board* whitePawnBoard = new Board(WHITE, PAWN, 0);
    Board* whiteKnightBoard = new Board(WHITE, KNIGHT, 0);
    Board* whiteBishopBoard = new Board(WHITE, BISHOP, 0);
    Board* whiteRookBoard = new Board(WHITE, ROOK, 0);
    Board* whiteQueenBoard = new Board(WHITE, QUEEN, 0);
    Board* whiteKingBoard = new Board(WHITE, KING, 0);

    Board* blackPawnBoard = new Board(BLACK, PAWN, 0);
    Board* blackKnightBoard = new Board(BLACK, KNIGHT, 0);
    Board* blackBishopBoard = new Board(BLACK, BISHOP, 0);
    Board* blackRookBoard = new Board(BLACK, ROOK, 0);
    Board* blackQueenBoard = new Board(BLACK, QUEEN, 0);
    Board* blackKingBoard = new Board(BLACK, KING, 0);

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

    FileIO file;

    //Placement
//    file.parseFile("PLA1", allBoards, mainBoard);
//    file.parseFile("RDD4", allBoards, mainBoard);
//    file.parseFile("QLB7", allBoards, mainBoard);
//    file.parseFile("NLF5", allBoards, mainBoard);
//    file.parseFile("PDH8", allBoards, mainBoard);
//    file.parseFile("PLA3", allBoards, mainBoard);
    file.parseFile("PLD1", allBoards, mainBoard);

    Display display;
    display.DrawBoard(mainBoard->board);

    //Movements
    file.parseFile("A1B1", allBoards, mainBoard);

//    display.DrawBoard(mainBoard->board);

    Board* mainTestBoard = new Board(COLOR_DEFAULT, PIECE_DEFAULT, 0);
    Board* testRookBoard = new Board(WHITE, ROOK, 129);
    Board* testPawnBoard = new Board(BLACK, PAWN, 8);

    mainTestBoard->setBitBoard();
    testRookBoard->setBitBoard();
    testPawnBoard->setBitBoard();

    mainTestBoard->board |= testRookBoard->board;
    mainTestBoard->board |= testPawnBoard->board;
    mainTestBoard->setBitBoard();

    testRookBoard->setBitMask(M42::calc_rook_attacks(0, mainBoard->board));
//    display.DrawBoard(mainTestBoard->board);
//    display.DrawBoard(testRookBoard->bitMask);

    return 0;
}