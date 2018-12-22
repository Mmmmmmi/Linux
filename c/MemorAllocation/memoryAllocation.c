#include "head.h"
#include <stdio.h>

//首次适应算法
struct Node* FF(struct memLinkList *pmemlist, size_t allocatesize)
{
    struct Node *cur = NULL;
    struct Node *temp = NULL;
    assert(pmemlist != NULL);
    if (allocatesize == 0) {
        return pmemlist->_emptylist._head;
    }
    sortAscAdr(pmemlist);
    cur = pmemlist->_emptylist._head;
    while (cur != NULL) {
        if (cur->_data._size >= allocatesize) {
            //找到了需要分配的空间 
            if (cur->_data._size == allocatesize) {
                //如果相等的话，不需要创建新的
                //直接把当前的挂在占用的内存链表的最后一个即可
                if (cur->_prev == pmemlist->_emptylist._tail) {      //找到的是第一个
                    pmemlist->_emptylist._head = cur->_next;
                }
                if (cur->_next == pmemlist->_emptylist._head) {      //找到的是最后一个
                    pmemlist->_emptylist._tail = cur->_prev;
                }
                //当前节点的下一个的prev指向当前节点的上一个
                cur->_next->_prev = cur->_prev;
                //当前节点的上一个的next指向当前节点的下一个
                cur->_prev->_next = cur->_next;
                if (pmemlist->_emptylist._head == pmemlist->_emptylist._tail) {
                    //找完之后的头等于尾
                    //说明空闲链表中就只有一个 并且被分配出去了
                    pmemlist->_emptylist._head = NULL;
                    pmemlist->_emptylist._tail = NULL;
                }
                //cur指向的就是需要加到usedmemlist中去的
                temp = cur;        
            }else {
               //找到的第一个大于需要的，需要从中分配一段空间 
                temp = creatNode(cur->_data._begin, allocatesize);
                //分配后空闲内存的节点需要发生改变
                cur->_data._begin = cur->_data._begin + allocatesize;
                cur->_data._size -= allocatesize;
            }
            //尾插到使用的最后一个
            usedMemeryPush(pmemlist, temp);
            break;
        }
        cur = cur->_next;
        if (cur == pmemlist->_emptylist._head) {
            break;
        }
    }
    if (temp == NULL) {
        printf("没有可分配的内存!\n");
    }
    //把当前操作的返回
    return cur;
}


struct Node *prevemptynode = NULL;
//定义一个指向上一次操作的节点　在循环首次适应里面会用到
//如果连续两次都选择循环首次适应算法，那么第二次的适应算法查找的起点是上一次的下一个　

//循环首次适应算法
struct Node* NF(struct memLinkList *pmemlist, size_t allocatesize)
{
    struct Node *temp = NULL;      //记录本次被分配的内存块是哪一个
    struct Node *cur = NULL;    
    assert(pmemlist != NULL);
    sortAscAdr(pmemlist);
    if (allocatesize == 0) {
        //如果需要分配的空间为0 直接返回
        return pmemlist->_emptylist._head;
    }
    if (prevemptynode == NULL) {
        //循环适应算法
        //第一次从头开始
        //后面的都操作的起点是上次操作节点的下一个
        cur = pmemlist->_emptylist._head;
    }else {
        cur = prevemptynode;
    }
    while (cur != NULL) {
        if (cur->_data._size >= allocatesize) {
            //找到了需要分配的空间 
            prevemptynode = cur->_next;
            if (cur->_data._size == allocatesize) {
                //如果相等的话，不需要创建新的
                //直接把当前的挂在占用的内存链表的最后一个即可
                if (cur->_prev == NULL) {      //找到的是第一个
                    pmemlist->_emptylist._head = cur->_next;
                }
                if (cur->_next == NULL) {      //找到的是最后一个
                    pmemlist->_emptylist._tail = cur->_prev;
                }
                if (cur->_next != NULL) {      //当前节点的下一个的prev指向当前节点的上一个
                    cur->_next->_prev = cur->_prev;
                }
                if (cur->_prev != NULL) {      //当前节点的上一个的next指向当前节点的下一个
                    cur->_prev->_next = cur->_next;
                }
                //cur指向的就是需要加到usedmemlist中去的
                temp = cur;        
            }else {
                //找到的第一个大于需要的，需要从中分配一段空间 
                temp = creatNode(cur->_data._begin, allocatesize);
                //分配后空闲内存的节点需要发生改变
                cur->_data._begin = cur->_data._begin + allocatesize;
                cur->_data._size -= allocatesize;
            }
            //尾插到使用的最后一个
            usedMemeryPush(pmemlist, temp);
            break;
        }
        cur = cur->_next;
        if (cur == prevemptynode) {
            //能走到这，就说明
            //找了一圈 没找到
            break;
        }
    }
    if (temp == NULL) {
        printf("没有可分配的内存!\n");
    }
    //把当前操作的返回
    return temp;
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


void allocateMemory(struct memLinkList *pmemlist, int n)
{
    size_t allocatesize = 0;
    printf("请输入要分配的内存大小:");
    scanf("%lu", &allocatesize);
    switch(n) {
        case 1:
            //首次适应算法
            FF(pmemlist, allocatesize);
            break;
        case 2:
            //循环首次适应算法
            prevemptynode = NF(pmemlist, allocatesize);
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

void recoveryMemory(struct memLinkList *pmemlist)
{   
    assert(pmemlist != NULL);
    size_t membegin = 0;
    printf("请输入要回收的内存的起始地址:");
    scanf("%lu", &membegin);
    //知道起始地址以后，在已分配内存链表中查找，找到后，将其取出来，
    //然后将空闲链表按地址升序排序，排序后将要回收的插入链表中，
    //进行可能的合并
    struct Node *ret = searchUsedMemery(pmemlist, membegin);
    //在已分配链表中找到要回收的
    if (ret == NULL) {
        return;
    }
    sortAscAdr(pmemlist);   //按地址排序
    emptyMemeryPush(pmemlist, ret);  //插入　＋ 合并
}



int main()
{
    size_t membegin = 0;
    size_t memsize = 0;
    int i = 0;
    int n = 0;
    struct memLinkList memlist;
    printf("please input memery begin: ");
    scanf("%lu", &membegin);
    printf("please input memery szie : ");
    scanf("%lu", &memsize);
    memListInit(&memlist, membegin, memsize);
    printf("请输入选项");
    printf("1.首次适应算法  2.循环首次适应算法  3.最佳适应算法  4.最坏适应算法 :");
    scanf("%d", &n);       //没有进行输入错误处理，直接当输入的正确
    while (1) {
        printList(&memlist);
        printf("请选择功能: ");
        printf("1.分配空间    2.回收空间   3.退出: ");
        scanf("%d", &i);
        switch(i) {
        case 1:
            allocateMemory(&memlist, n);
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
