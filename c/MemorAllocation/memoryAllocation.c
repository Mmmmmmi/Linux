
#include "head.h"
#include <stdio.h>


void FF() {
    
}

void allocateMemory(struct memLinkList *memlist)
{
    int i;
    printf("请输入选项");
    printf("1.首次适应算法  2.循环首次适应算法  3.最佳适应算法  4.最坏适应算法 :");
    scanf("%d", &i);

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
    printf("please input memery szie: ");
    scanf("%lu", &memsize);
    memListInit(&memlist, membegin, memsize);

    while (1) {
            printf("请选择功能: ");
            printf("1.分配空间    2.回收空间: ");
            scanf("%d", &i);
            switch(i) {
            case 1:
                allocateMemory(&memlist);
            case 2:
                recoveryMemory(&memlist);
                
            }
        }

        return 0;
}

