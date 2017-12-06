//TODO: Finish movement check if space is available or if it is the opposite color.
//TODO: For movement check if path is clear and if the end space is clear.
//TODO: For capture, just check if the path is clear and that the end space is an enemy.
//TODO: Make the board drawing abstract.
//TODO: Combine white/black boards.

#include "M42/m42.h"
#include "gameHandler.h"

int main() {
    gameHandler game;
    M42::init();
    game.init();

    bool isRunning = true;

//    while (isRunning) {
//        game.draw();
//        isRunning = game.update();
//    }

    display d;
    turnHandler* t = new turnHandler();
    board* mainBoard = new board(COLOR_DEFAULT, PIECE_DEFAULT, 0);
    board* testKnightBoard = new board(WHITE, QUEEN, 0);
    board* testPawnBoard = new board(BLACK, PAWN, 0);
    testKnightBoard->placePiece("D", "4");
    testPawnBoard->placePiece("E", "6");
    std::vector<board*> allBoards;
    allBoards.push_back(testKnightBoard);
    allBoards.push_back(testPawnBoard);
    utils::combineBoards(allBoards, mainBoard);
    d.drawBoard(allBoards);
    testKnightBoard->bitMask = M42::knight_attacks(utils::getPieceLocation("D", "4"));
    d.drawBoard(testKnightBoard->bitMask);
    std::cout << std::bitset<64>(testKnightBoard->bitMask & mainBoard->b) << std::endl;

    return 0;
}