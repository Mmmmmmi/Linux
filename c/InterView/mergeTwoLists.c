//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

//示例：

//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include<stdio.h>


struct ListNode {
     int val;
     struct ListNode *next;
 };


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* ret = NULL;
    struct ListNode* cur1 = NULL;
    struct ListNode* cur2 = NULL;
    struct ListNode* curret = NULL;
    struct ListNode* temp = NULL;
    if (l1 == NULL) {
        return l2;
    }  
    if (l2 == NULL) {
        return l1;
    }
    cur1 = l1;
    cur2 = l2;
    while(cur1 != NULL && cur2 != NULL) {
        if (cur1->val <= cur2->val) {
            if (ret == NULL) {
                ret = cur1;
                curret = cur1;
            }
            temp = cur1->next;
            curret->next = cur1;
            curret = cur1;
            cur1 = temp;

        }else {
            if (ret == NULL) {
                ret = cur2;
                curret = cur2;
            }
            temp = cur2->next;
            curret->next = cur2;
            curret = cur2;
            cur2 = temp;
        }
        
    }
    curret->next = cur1 == NULL ? cur2 : cur1;
    return ret;
}


int main()
{
    struct ListNode l1 = {1, NULL};
    struct ListNode l2 = {2, NULL};
    struct ListNode l3 = {4, NULL};
    struct ListNode l4 = {1, NULL};
    struct ListNode l5 = {3, NULL};
    struct ListNode l6 = {4, NULL};
  /*  struct ListNode l7 = {5, NULL};
    struct ListNode l8 = {5, NULL};
    struct ListNode l9 = {5, NULL};
    struct ListNode l10= {5, NULL};
    struct ListNode l11= {5, NULL};
    struct ListNode l13= {5, NULL};
    struct ListNode l14= {5, NULL};
*/
    l1.next = &l2;
    l2.next = &l3;
    l4.next = &l5;
    l5.next = &l6;
    struct ListNode *ret = mergeTwoLists(&l1, &l4);
    while (ret != NULL) {
        printf(" %d ->", ret->val);
        ret = ret->next;
    }
    printf("\n");
    return 0;
}

