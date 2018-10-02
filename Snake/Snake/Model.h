#ifndef __MODEL_H__
#define __MODEL_H__

typedef enum Direction{
	UP, DOWN, LEFT, RIGHT
}Direction;

typedef struct Position{
	int x;
	int y;
}Position;

typedef struct Node{
	Position pos;
	struct Node *next;
}Node;


typedef struct Snake{
	Node *head;
	Node *tail;
	Direction direction;
}Snake;

typedef struct Game {
	Snake snake;        //蛇
    //由于蛇目前只会增长,所以为了减少时间复杂度,
    //让链表头当蛇的尾巴,增长不用遍历,只需要头插.
	Position food;      //食物坐标
	int width;          //宽
	int height;         //高
    int speed;          //速度
    int score;          //分数
}Game;


void SnakeInitialize(Snake *psnake);               //蛇初始化
void GenerateFood(Game *pgame);                    //食物初始化
void GameInitialize(Game *pgame);				   //游戏初始化
void SnakeAddHead(Game *pGame);
void SnakeRemoveTail(Game *pGame);
void SnakeTest();
#endif // !__MODEL_H__

