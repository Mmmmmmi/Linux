/*
*   给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
*  
*  示例 1:
*  
*  输入: 1->2->3->4->5->NULL, k = 2
*  输出: 4->5->1->2->3->NULL
*  解释:
*  向右旋转 1 步: 5->1->2->3->4->NULL
*  向右旋转 2 步: 4->5->1->2->3->NULL
*  示例 2:
*  
*  输入: 0->1->2->NULL, k = 4
*  输出: 2->0->1->NULL
*  解释:
*  向右旋转 1 步: 2->0->1->NULL
*  向右旋转 2 步: 1->2->0->NULL
*  向右旋转 3 步: 0->1->2->NULL
*  向右旋转 4 步: 2->0->1->NULL
*
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*class Solution {
*   public:
*   ListNode* rotateRight(ListNode* head, int k) {
*   }
*};
*/


#include <iostream>
using namespace std;
struct ListNode {
     int val;
     struct ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    struct ListNode* rotateRight(struct ListNode* head, int k) {
        if (k < 0 || head == NULL) {
            return NULL;
        }

        //计算链表的长度
        int count = 0;
        struct ListNode* cur = head;
        while(cur != NULL) {
            count++;
            cur = cur->next;
        }

        //算出真实需要挪几次
        k %= count;
    

        while (k--) {
            cur = head;
            int beforeval = head->val;
            int curval = head->val;
            while(cur != NULL) {
                    // 1  2   3
                    // 3  1   2
                    // 2  3   1
                    // 1  2   3
                curval = cur->val; 
                cur->val = beforeval;
                beforeval = curval;
                cur = cur->next;
            }
            head->val = beforeval;
        }
        return head;
    }
};

int main()
{
    struct ListNode l1(1);
    struct ListNode l2(2);
    struct ListNode l3(3);
    struct ListNode l4(4);
    struct ListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    Solution s1;
    struct ListNode* lRet = s1.rotateRight(&l1, 3);
    while(lRet) {
        cout<< lRet->val << " ";
        lRet = lRet->next;
    }
    cout<<endl;
    return 0;
}

