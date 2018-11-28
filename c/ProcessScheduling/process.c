#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"


void FCFS(Queue *pqueue, PCB pcbs[], int size)
{
    int pcbnumber = size;
	int time = 0;
	//
	//  |_______|_______|_______|_______|_______|_______|_______|_______|___
	//	0       1       2       3       4       5       6       7       8 

	while (1) {
		//等待进程
        for (int i = 0; i < size; i++) {
            if (pcbs[i].ArrivalTime == time) {
                QueuePush(pqueue, pcbs[i]);
         //       printf("QueueTop(pqueue)->next == %p\n", QueueTop(pqueue)->next);
			    printf("PCB %c ARRIVAL TIME IS %d\n", pcbs[i].name, time);
                pcbnumber--;
		//	    printf("pcbnumber == %d\n", pcbnumber);
            }
        }
		//printf("QueueSize(pqueue) == %lu   QueueEmpty(pqueue) == %d\n", QueueSize(pqueue), QueueEmpty(pqueue));
        if (QueueEmpty(pqueue) && pcbnumber == 0) {
			printf("进程执行完毕！\n");
			break;
		}
        //
        //显示时间
		printf("time is %d \n", time);

		//执行进程
		if (time == 0 || QueueTop(pqueue)->data.ResidualTime == 0) {
            if (time != 0) {
                printf("PCB %c FINISH TIME IS %d\n", QueueTop(pqueue)->data.name, time);
                QueuePop(pqueue);
            }
		}

        if (time != 0 && !QueueEmpty(pqueue)) {
            QueueTop(pqueue)->data.ResidualTime--;
        }

		time++;
        sleep(1);
	}
}

void RR(Queue *pqueue, PCB pcbs[], int size)
{
	//这里是时间片的大小
	int q = 2;
	
	//这个表示本次时间片q剩下多少
	int lessq = 0;

	int pcbid = 0;

    int pcbnumber = size;
	//表示本进程还需要的服务时间
	int curPcbServiceTime = 0;
	Node *cur = NULL;
	int time = 0;
	//
	//  |_______|_______|_______|_______|_______|_______|_______|_______|___
	//	0       1       2       3       4       5       6       7       8 


	while (1) {
		//等待进程
		if (pcbid == -1 && QueueEmpty(pqueue) && pcbnumber == 0) {
			printf("进程执行完毕！\n");
			break;
		}
		if (pcbid != -1) {
			QueuePush(pqueue, pcbs[pcbid]);
			printf("PCB %c ARRIVAL TIME IS %d\n", QueueTop(pqueue)->data.name, time);
            pcbnumber--;
		}
		printf("time is %d \n", time);
		//执行进程
		if (lessq == 0) {
			if (curPcbServiceTime == 0) {
				if (time != 0) {
					printf("PCB %c FINISH TIME IS %d\n", QueueTop(pqueue)->data.name, time);
					QueuePop(pqueue);
				}
			}
			else {
				QueueTop(pqueue)->data.ResidualTime = curPcbServiceTime;
				pqueue->rear->next = pqueue->front;
				pqueue->rear = pqueue->rear->next;
				pqueue->front = pqueue->front->next;
				pqueue->rear->next = NULL;
			}
			if (!QueueEmpty(pqueue)) {
				curPcbServiceTime = QueueTop(pqueue)->data.ResidualTime;
			}
			lessq = 2;
		}
		else {
			if (curPcbServiceTime == 0) {
				printf("PCB %c FINISH TIME IS %d\n", QueueTop(pqueue)->data.name, time);
				QueuePop(pqueue);
				if (!QueueEmpty(pqueue)) {
					curPcbServiceTime = QueueTop(pqueue)->data.ResidualTime;
					lessq = 2;
				}
			}
		}
		lessq--;
		curPcbServiceTime--;
		time++;
        sleep(1);
	}
}


void SPF(PCB pcbs[], size_t size)
{

	int pcbid = 0;
    Node *head = NULL;
	Node *cur = NULL;
	int time = 0;
	//
	//  |_______|_______|_______|_______|_______|_______|_______|_______|___
	//	0       1       2       3       4       5       6       7       8 

	while (1) {
		//等待进程
//		if ((pcbid = getPcb(pcbs, size, time)) == -1 && head == NULL) {
			printf("进程执行完毕！\n");
			break;
//		}
		printf("time is %d \n", time);
		if (pcbid != -1) {
		}
		//执行进程
	}
}


int main()
{
	Queue queue;
 // char name;
 // int ArrivalTime;        //到达时间
 // int ServiceTime;        //服务时间
 // int StartTime;          //开始时间
 // int FinishTime;         //完成时间
 // int ResidualTime;       //剩余服务时间
 // int WholeTime;          //周转时间
 // int weightWholeTime;    //带权周转时间
	PCB p1 = { 'A' ,0, 4, 0, 0, 4, 0, 0};
    PCB p2 = { 'B' ,1, 3, 0, 0, 3, 0, 0};
    PCB p3 = { 'C' ,2, 4, 0, 0, 4, 0, 0};
    PCB p4 = { 'D' ,3, 2, 0, 0, 2, 0, 0};
    PCB p5 = { 'E' ,4, 4, 0, 0, 4, 0, 0};
   // PCB pcbs[] = {p1};
    PCB pcbs[] = { p1, p2, p3, p4, p5 };
	int size = sizeof(pcbs) / sizeof(pcbs[0]);
	QueueInit(&queue);
	int input = 0;
	printf("1. FCFS   2.RR   3.SPN\n");
	printf("Please input number: ");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		FCFS(&queue, pcbs, size);
		break;
	case 2:
		RR(&queue, pcbs, size);
		break;
	case 3:
        SPF(pcbs, size);
		break;
	default:
		break;
	}
	QueueDestroy(&queue);
	return 0;
}
