//
// Created by Dan on 12/6/2017.
//

#include "GameHandler.h"

bool GameHandler::init() {

    turn = new TurnHandler();

    mainBoard = new Board(COLOR_DEFAULT, PIECE_DEFAULT, 0);

    whitePawnBoard = new Board(WHITE, PAWN, 0);
    whiteKnightBoard = new Board(WHITE, KNIGHT, 0);
    whiteBishopBoard = new Board(WHITE, BISHOP, 0);
    whiteRookBoard = new Board(WHITE, ROOK, 0);
    whiteQueenBoard = new Board(WHITE, QUEEN, 0);
    whiteKingBoard = new Board(WHITE, KING, 0);

    blackPawnBoard = new Board(BLACK, PAWN, 0);
    blackKnightBoard = new Board(BLACK, KNIGHT, 0);
    blackBishopBoard = new Board(BLACK, BISHOP, 0);
    blackRookBoard = new Board(BLACK, ROOK, 0);
    blackQueenBoard = new Board(BLACK, QUEEN, 0);
    blackKingBoard = new Board(BLACK, KING, 0);

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

    //Placement
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


    for (Board* board : allBoards) {
        if (board->boardColor == WHITE) {
            allWhiteBoards.push_back(board);
        } else if (board->boardColor == BLACK) {
            allBlackBoards.push_back(board);
        }
    }

    Utils::combineBoards(allBoards, mainBoard);
    Utils::combineBoards(allWhiteBoards, whiteBoard);
    Utils::combineBoards(allBlackBoards, blackBoard);

    return true;
}

bool GameHandler::draw() {
    screen.drawBoard(allBoards);
    std::cout << "It is " << ColorEnum::colorToString(turn->getCurrentTurn()) << "'s turn to move." << std::endl;
    return true;
}

bool GameHandler::update() {
    if (file.parseFile(file.getUserInput(), allBoards, mainBoard, turn)) {
        turn->changeTurn();
        return true;
    }
    return false;
}

bool GameHandler::hasWon() {

    if (whiteKingBoard->board == 0) {
        std::cout << "Black Wins!" << std::endl;
        return true;
    }
    if (blackKingBoard->board == 0) {
        std::cout << "White Wins!" << std::endl;
        return true;
    }

    return false;
}
