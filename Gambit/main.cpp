//TODO: Finish movement check if space is available or if it is the opposite color.
//TODO: For movement check if path is clear and if the end space is clear.
//TODO: For capture, just check if the path is clear and that the end space is an enemy.

#include "Board.h"
#include "Display.h"
#include "FileIO.h"
#include "M42/m42.h"

int main() {
    M42::init();

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
    Display display;


//    while (true) {
//        display.drawBoard(mainBoard->board);
//        file.parseFile(file.getUserInput(), allBoards, mainBoard);
//    }

    //Placement
    file.parseFile("RLA1", allBoards, mainBoard);
    file.parseFile("NLB1", allBoards, mainBoard);
    file.parseFile("BLC1", allBoards, mainBoard);
    file.parseFile("QLD1", allBoards, mainBoard);
    file.parseFile("KLE1", allBoards, mainBoard);
    file.parseFile("BLF1", allBoards, mainBoard);
    file.parseFile("NLG1", allBoards, mainBoard);
    file.parseFile("RLH1", allBoards, mainBoard);

    file.parseFile("PLA2", allBoards, mainBoard);
    file.parseFile("PLB2", allBoards, mainBoard);
    file.parseFile("PLC2", allBoards, mainBoard);
    file.parseFile("PLD2", allBoards, mainBoard);
    file.parseFile("PLE2", allBoards, mainBoard);
    file.parseFile("PLF2", allBoards, mainBoard);
    file.parseFile("PLG2", allBoards, mainBoard);
    file.parseFile("PLH2", allBoards, mainBoard);


    file.parseFile("RDA8", allBoards, mainBoard);
    file.parseFile("NDB8", allBoards, mainBoard);
    file.parseFile("BDC8", allBoards, mainBoard);
    file.parseFile("QDD8", allBoards, mainBoard);
    file.parseFile("KDE8", allBoards, mainBoard);
    file.parseFile("BDF8", allBoards, mainBoard);
    file.parseFile("NDG8", allBoards, mainBoard);
    file.parseFile("RDH8", allBoards, mainBoard);

    file.parseFile("PDA7", allBoards, mainBoard);
    file.parseFile("PDB7", allBoards, mainBoard);
    file.parseFile("PDC7", allBoards, mainBoard);
    file.parseFile("PDD7", allBoards, mainBoard);
    file.parseFile("PDE7", allBoards, mainBoard);
    file.parseFile("PDF7", allBoards, mainBoard);
    file.parseFile("PDG7", allBoards, mainBoard);
    file.parseFile("PDH7", allBoards, mainBoard);

//    display.drawBoard(mainBoard->board);

    //Movements
//    file.parseFile("A2H8", allBoards, mainBoard);

//    display.drawBoard(mainBoard->board);
    while (true) {
        display.drawBoard(allBoards);
        file.parseFile(file.getUserInput(), allBoards, mainBoard);
    }

    return 0;
}