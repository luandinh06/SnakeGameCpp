#include "snakeGame.h"

SnakeGame::SnakeGame() {}

void SnakeGame::init(){
    createField();

    createSnake(&this->locations,this->location.x,this->location.y);
    drawSnake(&this->locations);

    ramdomFood();
}

void SnakeGame::createField(){
    gotoXY(this->Xint,this->Yint);
    vertical(this->XlengthField);
    gotoXY(this->Xint,this->Yint + this->YlengthField -1);
    vertical(this->XlengthField);
    horizontal(this->Xint,this->Yint,this->YlengthField);
    horizontal(this->Xint + this->XlengthField - 1,this->Yint, this->YlengthField);
}

void SnakeGame::vertical(int XlengthField){
    for (int i = 0; i < XlengthField; i++)
    {
        cout << edgeSign;
    }
}

void SnakeGame::horizontal(int x, int y,int maxY){
    for (int i = 0; i <= (maxY-1); i++)
    {
        gotoXY(x,y);
        cout << edgeSign;
        y++;
    }
}

void SnakeGame::createSnake(vector<Location>* locations, int x, int y)
{
	for (int i = 0;i < this->length;i++)
	{
        Location location = {x,y};
		locations->push_back(location);
		x--;
	}
}

void SnakeGame::drawSnake(vector<Location>* locations){
    for (size_t i = 0; i < locations->size(); ++i) {
        gotoXY((*locations)[i].x + this->Xint, (*locations)[i].y + this->Yint);
        if(i == 0) cout << headSnakeSign;
        else cout << snakeSign;
    }
}

void SnakeGame::ramdomFood()
{
    do {
    srand(static_cast<unsigned int>(time(0)));
    this->food.x = rand() % (this->XlengthField - 4) + 2;
	this->food.y = rand() % (this->YlengthField - 4) + 2;
    } while (isFoodInSnake());

	gotoXY(this->food.x + this->Xint, this->food.y + this->Yint);
	cout << "$";
}

bool SnakeGame::isFoodInSnake()
{
    for (size_t i = 0; i < this->locations.size(); ++i) {
        if(this->food.x == this->locations[i].x && this->food.y == this->locations[i].y){
            return true;
        }
    }
	return false;
}

void SnakeGame::start(){
        
    if(kbhit())
    {
        char key = getch();
        if(key == -32){
            key = getch();
            switch (key)
            {
                case KEY_UP:
                    if(this->direction != DIRECTION_DOWN) this->direction = DIRECTION_UP;
                    break;
                case KEY_DOWN:
                    if(this->direction != DIRECTION_UP) this->direction = DIRECTION_DOWN;
                    break;
                case KEY_LEFT:
                    if(this->direction != DIRECTION_RIGHT) this->direction = DIRECTION_LEFT;
                    break;
                case KEY_RIGHT:
                    if(this->direction != DIRECTION_LEFT) this->direction = DIRECTION_RIGHT;
                    break;
                default:
                    break;
            }
        }
    }    

    if (this->direction == DIRECTION_UP) this->location.y--;
    else if (this->direction == DIRECTION_DOWN) this->location.y++;
    else if (this->direction == DIRECTION_LEFT) this->location.x--;
    else if (this->direction == DIRECTION_RIGHT) this->location.x++;

    clearSnake(&this->locations);

    this->locations.insert(this->locations.begin(), this->location);
    if( !isSnakeEatFood( &this->food, &this->locations)) this->locations.pop_back();

    drawSnake(&this->locations);

    gotoXY(1,1);
    cout << "Point : " << this->point << endl;

    if(isSnakeEatItSelf() || isSnakeHitWall()) {
        this->isGameOver = true;
        gotoXY(1,2);
        cout << "Game Over, Press to start over";
    }
}

void SnakeGame::clearSnake(vector<Location>* locations)
{
    for (size_t i =0; i < locations->size(); i++)
	{
		gotoXY((*locations)[i].x + this->Xint,(*locations)[i].y + this->Yint);
        cout << " ";
	}
}

bool SnakeGame::isSnakeEatFood(Location* food,vector<Location>* locations)
{
	if ((locations->begin()->x == food->x) && (locations->begin()->y == food->y))
	{
        this->point++;
        ramdomFood();
		return true;
	}
	return false;
}

bool SnakeGame::isSnakeGameOver(){
    if(this->isGameOver) return true;
    return false;
}

bool SnakeGame::isSnakeEatItSelf()
{
	for (int i = 1;i < this->locations.size(); i++)
	{
		if ((this->locations[0].x == this->locations[i].x) && (this->locations[0].y == this->locations[i].y))
		{
			return true;
		}
	}
	return false;
}

bool SnakeGame::isSnakeHitWall()
{
	//ran cham tuong tren
	if (this->locations.begin()->y == 0 && (this->locations.begin()->x >= 0 && this->locations.begin()->x <= this->XlengthField))
	{
		return true;//gameover
	}
	//ran cham tuong duoi
	else if (this->locations.begin()->y == (this->YlengthField-1) && (this->locations.begin()->x >= 0 && this->locations.begin()->x <= this->XlengthField))
	{
		return true;//gameover
	}
	//ran cham tuong phai
	else if (this->locations.begin()->x == (this->XlengthField-1) && (this->locations.begin()->y >= 0 && this->locations.begin()->y <= this->YlengthField))
	{
		return true;//gameover
	}
	//ran cham tuong trai
	else if (this->locations.begin()->x == 0 && (this->locations.begin()->y >= 0 && this->locations.begin()->y <= this->YlengthField))
	{
		return true;//gameover
	}
    
	return false;
}

void SnakeGame::startOver(){
    system("cls");
    this->locations.clear();
    
    this->length = 4;
    this->location.x = 6;
    this->location.y = 6;
    this->direction = DIRECTION_RIGHT;
    this->point = 0;

    init();
    this->isGameOver = false;
}
