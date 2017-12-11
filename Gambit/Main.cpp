//TODO: Check/Checkmate, non-exposure moves
//TODO: Display available piece moves

#include "M42/m42.h"
#include "GameHandler.h"

int main() {
    GameHandler game;
    M42::init();
    game.init();

    bool isRunning = true;

    while (isRunning) {
        game.draw();
        game.update();
        isRunning = !game.hasWon();
    }

//    Display display;
//    FileIO file;
//    Board* mainBoard = new Board(COLOR_DEFAULT, PIECE_DEFAULT, 0);
//    Board* testKnightBoard = new Board(WHITE, KNIGHT, 0);
//    Board* testWhitePawnBoard = new Board(WHITE, PAWN, 0);
//    Board* testBlackPawnBoard = new Board(BLACK, PAWN, 0);
//
//    testKnightBoard->placePiece("D", "4");
//    testWhitePawnBoard->placePiece("C", "6");
//    testBlackPawnBoard->placePiece("E", "6");
//
//    std::vector<Board*> allBoards;
//    std::vector<Board*> whiteBoards;
//    std::vector<Board*> blackBoards;
//
//    allBoards.push_back(testKnightBoard);
//    allBoards.push_back(testWhitePawnBoard);
//    allBoards.push_back(testBlackPawnBoard);
//
//    for (Board* board : allBoards) {
//        if (board->boardColor == WHITE) {
//            whiteBoards.push_back(board);
//        } else if (board->boardColor == BLACK) {
//            blackBoards.push_back(board);
//        }
//    }
//
//    Utils::combineBoards(allBoards, mainBoard);
//
//
//    display.drawBoard(allBoards);
//    testKnightBoard->bitMask = M42::knight_attacks(Utils::getPieceLocation("D", "4"));
//    testWhitePawnBoard->bitMask = M42::pawn_attacks(testWhitePawnBoard->boardColor, Utils::getPieceLocation("C", "6"));
//    testBlackPawnBoard->bitMask = M42::pawn_attacks(testBlackPawnBoard->boardColor, Utils::getPieceLocation("E", "6"));
//    display.drawBoard(testKnightBoard->bitMask);
//    std::cout << std::bitset<64>(testKnightBoard->bitMask & mainBoard->board) << std::endl;
//
//    if (testKnightBoard->bitMask & testWhitePawnBoard->board) {
//        std::cout << "HIT" << std::endl;
//    } else {
//        std::cout << "MISS" << std::endl;
//    }

    return 0;
}