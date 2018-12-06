#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct memeryNode {
    size_t _begin;
    size_t _end;
    size_t _size;
};

typedef struct memeryNode DataType;

struct Node {
    struct memeryNode _data;
    struct Node* _next;
    struct Node* _prev;
};

struct LinkList {
    struct Node* _head;
    struct Node* _tail;
};


struct memLinkList {
    struct LinkList _emptylist;
    struct LinkList _usedlist;
};

void memListInit(struct memLinkList *pmemlist)
{
    pmemlist->_emptylist._head = NULL;
    pmemlist->_emptylist._tail = NULL;
    pmemlist->_usedlist._head = NULL;
    pmemlist->_usedlist._tail = NULL;
}

Node* creatNode(DataType *data)
{
    Node *temp = (struct Node*) malloc (sizeof(struct Node));
    assert(temp != NULL);
    temp->_data = *data;
    temp->_next = NULL;
    return temp;
}


void emptyMemeryPushBack(struct memLinkList *pmemlist, size_t memnumber)
{
    
}







#endif
