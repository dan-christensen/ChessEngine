//
// Created by Dan on 12/6/2017.
//

#include "gameHandler.h"

bool gameHandler::init() {

    turn = new turnHandler();

    mainBoard = new board(COLOR_DEFAULT, PIECE_DEFAULT, 0);

    whitePawnBoard = new board(WHITE, PAWN, 0);
    whiteKnightBoard = new board(WHITE, KNIGHT, 0);
    whiteBishopBoard = new board(WHITE, BISHOP, 0);
    whiteRookBoard = new board(WHITE, ROOK, 0);
    whiteQueenBoard = new board(WHITE, QUEEN, 0);
    whiteKingBoard = new board(WHITE, KING, 0);

    blackPawnBoard = new board(BLACK, PAWN, 0);
    blackKnightBoard = new board(BLACK, KNIGHT, 0);
    blackBishopBoard = new board(BLACK, BISHOP, 0);
    blackRookBoard = new board(BLACK, ROOK, 0);
    blackQueenBoard = new board(BLACK, QUEEN, 0);
    blackKingBoard = new board(BLACK, KING, 0);

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

    //placement
    file.parseFile("RLA1", allBoards, mainBoard, turn);
    file.parseFile("NLB1", allBoards, mainBoard, turn);
    file.parseFile("BLC1", allBoards, mainBoard, turn);
    file.parseFile("QLD1", allBoards, mainBoard, turn);
    file.parseFile("KLE1", allBoards, mainBoard, turn);
    file.parseFile("BLF1", allBoards, mainBoard, turn);
    file.parseFile("NLG1", allBoards, mainBoard, turn);
    file.parseFile("RLH1", allBoards, mainBoard, turn);

    file.parseFile("PLA2", allBoards, mainBoard, turn);
    file.parseFile("PLB2", allBoards, mainBoard, turn);
    file.parseFile("PLC2", allBoards, mainBoard, turn);
    file.parseFile("PLD2", allBoards, mainBoard, turn);
    file.parseFile("PLE2", allBoards, mainBoard, turn);
    file.parseFile("PLF2", allBoards, mainBoard, turn);
    file.parseFile("PLG2", allBoards, mainBoard, turn);
    file.parseFile("PLH2", allBoards, mainBoard, turn);


    file.parseFile("RDA8", allBoards, mainBoard, turn);
    file.parseFile("NDB8", allBoards, mainBoard, turn);
    file.parseFile("BDC8", allBoards, mainBoard, turn);
    file.parseFile("QDD8", allBoards, mainBoard, turn);
    file.parseFile("KDE8", allBoards, mainBoard, turn);
    file.parseFile("BDF8", allBoards, mainBoard, turn);
    file.parseFile("NDG8", allBoards, mainBoard, turn);
    file.parseFile("RDH8", allBoards, mainBoard, turn);

    file.parseFile("PDA7", allBoards, mainBoard, turn);
    file.parseFile("PDB7", allBoards, mainBoard, turn);
    file.parseFile("PDC7", allBoards, mainBoard, turn);
    file.parseFile("PDD7", allBoards, mainBoard, turn);
    file.parseFile("PDE7", allBoards, mainBoard, turn);
    file.parseFile("PDF7", allBoards, mainBoard, turn);
    file.parseFile("PDG7", allBoards, mainBoard, turn);
    file.parseFile("PDH7", allBoards, mainBoard, turn);

    return true;
}

bool gameHandler::draw() {
    display.drawBoard(allBoards);
    std::cout << "It is " << colorEnum::colorToString(turn->getCurrentTurn()) << "'s turn to move." << std::endl;
    if (file.parseFile(file.getUserInput(), allBoards, mainBoard, turn)) {
        turn->changeTurn();
    }
    return false;
}
