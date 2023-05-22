#include <iostream>
#include "snakeGame.h"

using namespace std;

int main(){
    SnakeGame snakegame;
    snakegame.init();
    while (true)
    {
        while (!snakegame.isSnakeGameOver())
        {
            snakegame.start();
            Sleep(200);
        }
        getchar();
        snakegame.startOver();

    }

    getch();
    return 0;
}