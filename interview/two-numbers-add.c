#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *cur1 = NULL;
    struct ListNode *cur2 = NULL;
    struct ListNode *newcur = NULL;
    struct ListNode *ret = NULL;
    struct ListNode *tmp = NULL;
    int cf = 0;
    cur1 = l1;
    if(l1 == NULL || l2 == NULL) {
        return NULL;
    }
    cur1 = l1;
    cur2 = l2;
    while(cur1 != NULL && cur2 != NULL) {
        tmp = (struct ListNode *) malloc (sizeof(struct ListNode));
        if (tmp == NULL) {
            return NULL;
        }
        tmp->val = cur1->val + cur2->val + cf;
        tmp->next = NULL;
        if (tmp->val / 10 >= 1) {
            cf = 1;
        }
        else {
            cf = 0;
        }
        tmp->val %= 10;
        if (ret == NULL) {
            tmp->next = ret;
            ret = tmp;
            newcur = tmp;
        }
        else {
            newcur->next = tmp;
            newcur = tmp;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    struct ListNode *cur = cur1;
    if (cur1 == NULL) {
        cur = cur2;
    }
    while(cur != NULL) {
        tmp = (struct ListNode *) malloc (sizeof(struct ListNode));
        if (tmp == NULL) {
            return NULL;
        }
        tmp->val = cur->val + cf;
        tmp->next = NULL;
        if (tmp->val / 10 >= 1) {
            cf = 1;
        }
        else {
            cf = 0;
        }
        tmp->val %= 10;
        newcur->next = tmp;
        newcur = tmp;
        cur = cur->next;
    }
    if (cf == 1) {
        tmp = (struct ListNode *) malloc (sizeof(struct ListNode));
        if (tmp == NULL) {
            return NULL;
        }
        tmp->val = cf;
        tmp->next = NULL;
        newcur->next = tmp;
    }
    return ret;

}

int main()
{
    struct ListNode a = {2,NULL};
    struct ListNode b = {4,&a};
    struct ListNode c = {3,&b};
    struct ListNode d = {5,NULL};
    struct ListNode e = {6,&d};
    struct ListNode f = {4,&e};
    struct ListNode *r = addTwoNumbers(&c,&f);
    while (r != NULL) {
        printf("%d", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;

}
