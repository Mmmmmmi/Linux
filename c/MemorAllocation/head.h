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
struct Node* creatNode(DataType *data)
{
    struct Node *temp = (struct Node*) malloc (sizeof(struct Node));
    assert(temp != NULL);
    temp->_data = *data;
    temp->_next = NULL;
    return temp;
}

//初始化
void memListInit(struct memLinkList *pmemlist)
{
    pmemlist->_emptylist._head = NULL;
    pmemlist->_emptylist._tail = NULL;
    pmemlist->_usedlist._head = NULL;
    pmemlist->_usedlist._tail = NULL;
}


void emptyMemeryPushBack(struct memLinkList *pmemlist, size_t memnumber)
{
    
}


#endif
