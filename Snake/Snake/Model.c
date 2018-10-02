
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "Model.h"
#include "time.h"

void SnakeInitialize(Snake *pSnake)
{
    int i = 0;
    assert(pSnake != NULL);
    pSnake->direction = RIGHT;
    pSnake->head = NULL;
	pSnake->tail = NULL;
     // 3,3   4,3    5,3
    for(i = 0; i < 3; i++) {
        int x = 3 + i;
        int y = 3;
        Node *newnode = (Node *)malloc(sizeof(Node));
        assert(newnode != NULL);
        newnode->pos.x = x;
        newnode->pos.y = y;
        newnode->next = pSnake->tail;
        pSnake->tail = newnode;
		if (pSnake->head == NULL) {
			pSnake->head = pSnake->tail;
		}
    }
}

static bool IsInSnake(int x, int y, Snake *pSnake)
{
    Node *cur = NULL;
    assert(pSnake != NULL);
    for (cur = pSnake->tail; cur != NULL; cur = cur->next) {
        if ((x == ((cur->pos).x)) && (y == ((cur->pos).y))) {
            return true;
        }
    }
    return false;
}

void GenerateFood(Game *pgame)
{
    int x = 0, y = 0;
    assert(pgame != NULL);
    do {
        x = rand()%(pgame->width);
        y = rand()%(pgame->height);
    }while(IsInSnake(x, y, &(pgame->snake)));
    (pgame->food).x = x;
    (pgame->food).y = y;
}


void GameInitialize(Game *pgame)
{
    assert(pgame != NULL);
    pgame->height = 27;
    pgame->width = 28;
    SnakeInitialize(&(pgame->snake));
    GenerateFood(pgame);
    pgame->speed = 300;
    pgame->score = 0;
}
void SnakeAddHead(Game *pGame)
{
    assert(pGame != NULL);
    Node *newnode = (Node *)malloc (sizeof(Node));
    assert(newnode != NULL);
    newnode->pos.x = (pGame->food).x;
    newnode->pos.y = (pGame->food).y;
    newnode->next = NULL;
    pGame->snake.head->next = newnode;
    pGame->snake.head = newnode;
}


void SnakeRemoveTail(Game *pGame)
{
    Node *del = NULL;
    assert(pGame != NULL);
    del = pGame->snake.tail;
    pGame->snake.tail = pGame->snake.tail->next;
    free(del);
    del = NULL;
}

void SnakeTest()
{
    Game game;
    GameInitialize(&game);
    printf("%d, %d\n", game.food.x, game.food.y);
}

