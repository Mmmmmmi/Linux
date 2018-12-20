#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//数据类型
struct memeryNode {
    size_t _begin;
    size_t _end;
    size_t _size;
};

typedef struct memeryNode DataType;

//节点结构体
struct Node {
    struct memeryNode _data;
    struct Node* _next;
    struct Node* _prev;
};

//链表结构体
struct LinkList {
    struct Node* _head;
    struct Node* _tail;
};

//内存链表
struct memLinkList {
    struct LinkList _emptylist;
    struct LinkList _usedlist;
};

//创建节点
//每个节点里面的数据域应该是起始地址和大小
//
// struct Node {
//    struct memeryNode _data;
//    struct Node* _next;
//    struct Node* _prev;
//};
struct Node* creatNode(size_t begin, size_t size)
{
    struct Node *temp = (struct Node*) malloc (sizeof(struct Node));
    //确保malloc 成功
    assert(temp != NULL);
    temp->_data._begin = begin;
    temp->_data._size = size;
    temp->_data._end = begin + size - 1;
    temp->_next = NULL;
    temp->_prev = NULL;
    return temp;
}

//输出链表
void printList(struct memLinkList *pmemlist)
{
    assert(pmemlist != NULL);
    struct Node *cur = NULL;
    //输出空闲链表
    cur = pmemlist->_emptylist._head;
    printf("空闲内存链表为：\n");
    while (cur != NULL) {
        printf("|begin:%3lu|    ", cur->_data._begin);
        cur = cur->_next;
    }
    printf("\n");
    cur = pmemlist->_emptylist._head;
    while (cur != NULL) {
        printf("|size :%3lu|", cur->_data._size);
        cur = cur->_next;
        if (cur != NULL) {
            printf("--->");
        }
    }
    printf("\n");
    cur = pmemlist->_emptylist._head;
    while (cur != NULL) {
        printf("|end  :%3lu|    ", cur->_data._end);
        cur = cur->_next;
    }
    printf("\n");
    //输出已分配内存链表
    cur = pmemlist->_usedlist._head;
    printf("已分配内存链表为：\n");
    while (cur != NULL) {
        printf("|begin:%3lu|    ", cur->_data._begin);
        cur = cur->_next;
    }
    printf("\n");
    cur = pmemlist->_usedlist._head;
    while (cur != NULL) {
        printf("|size :%3lu|", cur->_data._size);
        cur = cur->_next;
        if (cur != NULL) {
            printf("--->");
        }
    }
    printf("\n");
    cur = pmemlist->_usedlist._head;
    while (cur != NULL) {
        printf("|end  :%3lu|    ", cur->_data._end);
        cur = cur->_next;
    }
    printf("\n");
}

//初始化 
//需要初始化　内存的开始地址　和 大小
void memListInit(struct memLinkList *pmemlist, size_t begin, size_t size)
{
    assert(pmemlist != NULL);
    pmemlist->_emptylist._head = NULL;
    pmemlist->_emptylist._tail = NULL;
    pmemlist->_usedlist._head = NULL;
    pmemlist->_usedlist._tail = NULL;
    //先把第一个空的挂在空闲内存链表的第一个
    struct Node *ret = creatNode(begin, size);
    pmemlist->_emptylist._head = ret;
    pmemlist->_emptylist._tail = ret;
}

void Swap(struct Node *pnode1, struct Node *pnode2) 
{
    assert(pnode1 != NULL);
    assert(pnode2 != NULL);
    struct memeryNode temp;
    temp = pnode1->_data;
    pnode1->_data = pnode2->_data;
    pnode2->_data = temp;
}

//地址升序排序
void sortAscAdr(struct memLinkList *pmemlist)
{
    assert(pmemlist != NULL); 
    struct Node *cur = NULL;
    cur = pmemlist->_emptylist._head;
    while(cur->_next != NULL) {
        if (cur->_data._begin > cur->_next->_data._begin) {
            Swap(cur, cur->_next);
        }
       cur = cur->_next; 
    }
}

//内存块大小升序
void sortAscSize(struct memLinkList *pmemlist)
{
    assert(pmemlist != NULL);
    struct Node *cur = NULL;
    cur = pmemlist->_emptylist._head;
    while(cur->_next != NULL) {
        if (cur->_data._size > cur->_next->_data._size) {
            Swap(cur, cur->_next);
        }
       cur = cur->_next; 
    }
}


//内存块大小降序
void sortDescSize(struct memLinkList *pmemlist)
{
    assert(pmemlist != NULL);
    struct Node *cur = NULL;
    cur = pmemlist->_emptylist._head;
    while(cur->_next != NULL) {
        if (cur->_data._size < cur->_next->_data._size) {
            Swap(cur, cur->_next);
        }
       cur = cur->_next; 
    }
}

//占用中的内存块只需要添加到使用队列的最后一个就行了
void usedMemeryPush(struct memLinkList *pmemlist, struct Node * pnode)
{
    assert(pmemlist != NULL);
    assert(pnode != NULL);
    if (pmemlist->_usedlist._head == NULL) {   //说明已分配的为空
        pmemlist->_usedlist._head = pnode;
        pmemlist->_usedlist._tail = pnode;
    }else {
       pmemlist->_usedlist._tail->_next = pnode; 
       pnode->_prev = pmemlist->_usedlist._tail; 
       pmemlist->_usedlist._tail = pnode; 
    }
}

struct Node* searchUsedMemery(struct memLinkList *pmemlist, size_t membegin)
{   
    struct Node *cur = NULL;
    assert(pmemlist != NULL);
    cur = pmemlist->_usedlist._head;
    while (cur != NULL) {
        if (cur->_data._begin == membegin) {
            //找到了要回收的空间
            if (cur->_prev == NULL) {      //找到的是第一个
                pmemlist->_usedlist._head = cur->_next;
            }
            if (cur->_next == NULL) {      //找到的是最后一个
                pmemlist->_usedlist._tail = cur->_prev;
            }
            if (cur->_next != NULL) {      //当前节点的下一个的prev指向当前节点的上一个
                cur->_next->_prev = cur->_prev;
            }
            if (cur->_prev != NULL) {      //当前节点的上一个的next指向当前节点的下一个
                cur->_prev->_next = cur->_next;
            }
            break;
        }
        cur = cur->_next;
    }
    if (cur == NULL) {
        printf("没有找到需要回收的内存!\n");
    }
    return cur;
}

//可能有合并的情况
void mergeMemery(struct memLinkList *pmemlist, struct Node *pnode)
{
    assert(pmemlist != NULL);
    assert(pnode != NULL);
}


//回收的内存块只需要添加到第一个比他地址高的前面就好
void emptyMemeryPush(struct memLinkList *pmemlist, struct Node * pnode)
{
    assert(pmemlist != NULL);
    assert(pnode != NULL);
    if (pmemlist->_emptylist._head == NULL) {   //说明空闲链表的为空
        pmemlist->_emptylist._head = pnode;
        pmemlist->_emptylist._tail = pnode;
    }else {
        struct Node *cur = NULL;
        cur = pmemlist->_emptylist._head;
        while(cur != NULL) {
            if (cur->_data._begin > pnode->_data._begin) {
                //如果找到一个内存块的起始地址大于pnode的起始地址，说明pnode 在它的前面
                pnode->_next = cur;
                pnode->_prev = cur->_prev;
                if (cur->_prev != NULL) {
                    cur->_prev->_next = pnode;
                }
                cur->_prev = pnode;
                if (cur == pmemlist->_emptylist._head) {
                    //如果pnode 的begin是最小的
                    pmemlist->_emptylist._head = pnode;
                }

                //可能有合并的情况
                mergeMemery(pmemlist, pnode);

                break;
            }
            cur = cur->_next;
        }
        if (cur == NULL) {
            //说明没有找到地址比它大的　它是最后一块
            pmemlist->_emptylist._tail->_next = pnode;
            pnode->_prev = pmemlist->_emptylist._tail;
            pmemlist->_emptylist._tail = pnode;

            //可能有合并的情况
            mergeMemery(pmemlist, pnode);
            
        }
    }
}

#endif
