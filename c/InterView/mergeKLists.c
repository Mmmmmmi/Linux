//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

//示例:

//输入:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//输出: 1->1->2->3->4->4->5->6


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>
#include<unistd.h>

struct ListNode {
     int val;
     struct ListNode *next;
 };

void Print(struct ListNode *cur)
{
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}



struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* ret = NULL;
    struct ListNode* cur1 = NULL;
    struct ListNode* cur2 = NULL;
    struct ListNode* curret = NULL;
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
            }
            else {
                curret->next = cur1;
            }
            curret = cur1;
            cur1 = cur1->next;
        }else {
            if (ret == NULL) {
                ret = cur2;
            }
            else {
                curret->next = cur2;
            }
            curret = cur2;
            cur2 = cur2->next;
        }
        
    }
    curret->next = cur1 == NULL ? cur2 : cur1;
    return ret;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int i = 0;
    struct ListNode * ret = NULL;
    if (lists == NULL || listsSize == 0) {
        return NULL;
    }
    while (i < listsSize) {
        ret = mergeTwoLists(lists[i++], ret);
        Print(ret);
    }
    return ret;
}

int main()
{

   // [[1,4,5],[1,3,4],[2,6]]
    struct ListNode l1 = {1, NULL};
    struct ListNode l2 = {4, NULL};
    struct ListNode l3 = {5, NULL};
    
    
    struct ListNode l4 = {1, NULL};
    struct ListNode l5 = {3, NULL};
    struct ListNode l6 = {4, NULL};
    
    struct ListNode l7 = {2, NULL};
    struct ListNode l8 = {6, NULL};
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

    l7.next = &l8;
    struct ListNode *array[] = {&l1, &l4, &l7};
    int size = sizeof(array) / sizeof(array[0]);
    struct ListNode *ret = mergeKLists(array, size);
    Print(ret);
    return 0;
}
