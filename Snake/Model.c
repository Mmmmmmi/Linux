
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Model.h"

void SnakeInitialize(Snake *pSnake)
{
    int i = 0;
    pSnake->direction = RIGHT;
    pSnake->head = NULL;
    // 3,3   4,3    5,3
    for(i = 0; i < 3; i++) {
        int x = 3 + i;
        int y = 3;
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->pos.x = x;
        newnode->pos.y = y;
        pSnake->head->next = newnode;
        if (pSnake->tail == NULL) {
            pSnake->tail = pSnake->head;
        }
        pSnake->head = newnode;
    }
}


void GenerateFood(Game *pgame)
{
    assert(pgame != NULL);

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


void SnakeRemoveTail(Snake *pSnake)
{
    Node *cur = NULL;
    assert(pSnake != NULL); 
    cur = pSnake->head;
    while(cur->next->next != NULL) {
           cur = cur->next;
        }
    free(cur->next);
    cur->next = NULL;
}






void Test()
{
    Game game;
    GameInitialize(&game);
}

