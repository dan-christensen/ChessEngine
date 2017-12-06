//TODO: Finish movement check if space is available or if it is the opposite color.
//TODO: For movement check if path is clear and if the end space is clear.
//TODO: For capture, just check if the path is clear and that the end space is an enemy.

#include "M42/m42.h"
#include "gameHandler.h"

int main() {
    gameHandler game;
    M42::init();
    game.init();

    bool isRunning = true;

    while (isRunning){
        game.draw();
    }

    return 0;
}