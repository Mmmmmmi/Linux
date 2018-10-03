#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "Model.h"
#include "View.h"

void SnakeInitialize(Snake *pSnake)     
{
    int i = 0;
    assert(pSnake != NULL);
    pSnake->direction = LEFT;
    pSnake->head = NULL;
	pSnake->tail = NULL;
     // 3,3  <- 4,3    <-5,3
    for(i = DEFAULT_HEAD; i < DEFAULT_HEAD + 3; i++) {
        int x = DEFAULT_HEAD + i;
        int y = DEFAULT_HEAD;
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
    pgame->height = 28;
    pgame->width = 28;
    SnakeInitialize(&(pgame->snake));
    GenerateFood(pgame);
    pgame->speed = 300;
    pgame->score = 0;
}

void SnakeAddHead(Snake *pSnake, Position *nextpos)
{
    assert(pSnake != NULL);
    Node *newnode = (Node *)malloc (sizeof(Node));
    assert(newnode != NULL);
    newnode->pos.x = nextpos->x;
    newnode->pos.y = nextpos->y;
    newnode->next = NULL;
	PrintSnakeBlock(&(pSnake->head->pos), nextpos);
    pSnake->head->next = newnode;
    pSnake->head = newnode;
}

void SnakeRemoveTail(Snake *pSnake)
{
    Node *del = NULL;
    assert(pSnake != NULL);
    del = pSnake->tail;
	pSnake->tail = pSnake->tail->next;
	CleanSnakeBlock(&(del->pos));
	free(del);
    del = NULL;
}

int SnakeScoreSort(int size, int *prank)
{
	int i = 0, j = 0, flag = 0, ret = 0;
	assert(prank != NULL);
	for (i = 0; i < size - 1; i++) {
		for (j = size - 1 - i; j > 0; j--) {
			if (prank[j] > prank[j - 1]) {
				int tmp = prank[j - 1];
				prank[j - 1] = prank[j];
				prank[j] = tmp;
				flag = 1;
				ret = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
	//只要进行过交换就说明有新的成绩进入排行榜
	return ret;
}

void SnakeRankSave(int size, int *prank)
{
	int i = 0;
	FILE *pf = NULL;
	assert(prank != NULL);
	pf = fopen("Rank.dat", "w");
	assert(pf != NULL);
	for (i = 0; i < size; i++) {
		fputc(*(prank + i), pf);
	}
}

void SnakeRankRead(int size, int *prank)
{
	int i = 0, k = 0;
	assert(prank != NULL);
	FILE *pf = NULL;
	pf = fopen("Rank.dat", "a");
	pf = fopen("Rank.dat", "r");
	assert(pf != NULL);
	while ((i < size) && ((k = fgetc(pf)) != EOF)) {
		(*(prank + i++)) = k;
	}
}

void SnakeTest()
{
    Game game;
    GameInitialize(&game);
    printf("%d, %d\n", game.food.x, game.food.y);
}

