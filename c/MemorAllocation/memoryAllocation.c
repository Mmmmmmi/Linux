#include "head.h"
#include <stdio.h>

//首次适应算法
void FF(struct memLinkList *pmemlist, size_t allocatesize)
{
    assert(pmemlist != NULL);
    sortAscAdr(pmemlist);
}

//循环首次适应算法
void NF(struct memLinkList *pmemlist, size_t allocatesize)
{
   assert(pmemlist != NULL);
   sortAscAdr(pmemlist);
}

//最佳适应算法
void BF(struct memLinkList *pmemlist, size_t allocatesize)
{
   assert(pmemlist != NULL);
   sortAscSize(pmemlist); 
}

//最坏适应算法
void WF(struct memLinkList *pmemlist, size_t allocatesize)
{
   assert(pmemlist != NULL);
   sortAscSize(pmemlist); 
}

void allocateMemory(struct memLinkList *pmemlist)
{
    int i;
    size_t allocatesize = 0;
    printf("请输入要分配的内存大小:");
    scanf("%lu", &allocatesize);
    printf("请输入选项");
    printf("1.首次适应算法  2.循环首次适应算法  3.最佳适应算法  4.最坏适应算法 :");
    scanf("%d", &i);       //没有进行输入错误处理，直接当输入的正确
    switch(i) {
        case 1:
            //首次适应算法
            FF(pmemlist, allocatesize);
            break;
        case 2:
            //循环首次适应算法
            NF(pmemlist, allocatesize);
            break;
        case 3:
            //最佳适应算法
            BF(pmemlist, allocatesize);
            break;
        case 4:
            //最坏适应算法
            WF(pmemlist, allocatesize);
            break;
        default:
            printf("输入错误！\n");
            break;
    }
}

void recoveryMemory(struct memLinkList *memlist)
{
     
}

int main()
{
    size_t membegin = 0;
    size_t memsize = 0;
    int i = 0;
    struct memLinkList memlist;
    printf("please input memery begin: ");
    scanf("%lu", &membegin);
    printf("please input memery szie : ");
    scanf("%lu", &memsize);
    memListInit(&memlist, membegin, memsize);
    while (1) {
        printList(&memlist);
        printf("请选择功能: ");
        printf("1.分配空间    2.回收空间   3.退出: ");
        scanf("%d", &i);
        switch(i) {
        case 1:
            allocateMemory(&memlist);
            break;
        case 2:
            recoveryMemory(&memlist);
            break;
        case 3:
            printf("程序退出！\n");
            return 0;
        default:
            printf("选项输入有误，请重新输入！\n");
            break;
        }
    }
    return 0;
}
