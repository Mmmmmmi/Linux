#pragma once

typedef struct PCB {
	char name;
	int ArrivalTime;        //到达时间
	int ServiceTime;        //服务时间
	int StartTime;          //开始时间
	int FinishTime;         //完成时间
    int ResidualTime;       //剩余服务时间
	int WholeTime;          //周转时间
	int weightWholeTime;    //带权周转时间
}PCB;
typedef PCB DataType;
typedef struct Node {
	DataType data;
	struct Node *next;
}Node;
typedef struct Queue {
	Node *front;
	Node *rear;
	size_t size;			//队列中有几个元素
}Queue;

void QueueInit(Queue *pqueue) {			//初始化
	assert(pqueue != NULL);
	pqueue->front = NULL;
	pqueue->rear = NULL;
	pqueue->size = 0;
}

void QueueDestroy(Queue *pqueue)
{
	Node *cur = NULL;
	Node *del = NULL;
	assert(pqueue != NULL);
	if (pqueue->front == NULL) {
		return;
	}
	cur = pqueue->front;
	while (cur != NULL) {
		del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
}

Node *CreatNode(DataType data)
{
	Node *ret = (Node *)malloc(sizeof(Node));
	if (ret == NULL) {
		exit(0);
	}
	ret->data = data;
	ret->next = NULL;
	return ret;
}

void QueuePush(Queue *pqueue, DataType data)
{
	assert(pqueue != NULL);
	Node *temp = CreatNode(data);
	if (pqueue->front == NULL) {
		pqueue->front = temp;
		pqueue->rear = temp;
		//pqueue->rear = pqueue->front = temp;
		pqueue->size++;
	}
	else {
		pqueue->rear->next = temp;
		pqueue->rear = pqueue->rear->next;
		//pqueue->rear = temp;
		pqueue->size++;
	}
}

void QueuePop(Queue *pqueue)
{
	assert(pqueue != NULL);
	Node *del = NULL;
	assert(pqueue != NULL);
	if (pqueue->front == NULL) {
		return;
	}
	del = pqueue->front;
	pqueue->front = pqueue->front->next;
	free(del);
	del = NULL;
	pqueue->size--;
    
}

Node *QueueTop(Queue *pqueue)
{
	return pqueue->front;
}


bool QueueEmpty(const Queue *pqueue)
{
	return pqueue->front == NULL;
}

size_t QueueSize(const Queue *pqueue)
{
    return pqueue->size;
}
