#ifndef _SNAKE_GAME_H_
#define _SNAKE_GAME_H_

#include <iostream>
#include <vector>
#include "mylib.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#define DIRECTION_UP 0
#define DIRECTION_DOWN 1
#define DIRECTION_LEFT 2
#define DIRECTION_RIGHT 3

#define edgeSign '#'
#define snakeSign 'o'
#define headSnakeSign '+'

struct Location {
    int x;
    int y;
};

class SnakeGame {
public:
    SnakeGame();  // Constructor

    void init();
    void start();
    bool isSnakeGameOver();
    void startOver();

private:
    vector<Location> locations;
    Location location = {6, 6};
    Location food = {0, 0};
    bool isGameOver = false;
    int length = 4;
    int point = 0;
    int direction = DIRECTION_RIGHT;

    const int Xint = 5;
    const int Yint = 4;
    const int XlengthField = 20;
    const int YlengthField = 15;
    
    void vertical(int);
    void horizontal(int x, int y,int maxY);
    void createField();

    void createSnake(vector<Location>* locations, int x, int y);
    void drawSnake(vector<Location>* locations);

    void ramdomFood();
    bool isFoodInSnake();

    void clearSnake(vector<Location>* locations);
    bool isSnakeEatFood(Location* food,vector<Location>* locations);

    bool isSnakeEatItSelf();
    bool isSnakeHitWall();
};

#endif