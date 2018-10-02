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
	Snake snake;        //��
    //������Ŀǰֻ������,����Ϊ�˼���ʱ�临�Ӷ�,
    //������ͷ���ߵ�β��,�������ñ���,ֻ��Ҫͷ��.
	Position food;      //ʳ������
	int width;          //��
	int height;         //��
    int speed;          //�ٶ�
    int score;          //����
}Game;


void SnakeInitialize(Snake *psnake);               //�߳�ʼ��
void GenerateFood(Game *pgame);                    //ʳ���ʼ��
void GameInitialize(Game *pgame);				   //��Ϸ��ʼ��
void SnakeAddHead(Game *pGame);
void SnakeRemoveTail(Game *pGame);
void SnakeTest();
#endif // !__MODEL_H__

