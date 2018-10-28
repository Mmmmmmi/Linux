#include <stdio.h>
typedef struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 }TreeNode ;
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL || q == NULL) {
        if (p == q) {
            return true;
        }
        return false;
    }
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
int main()
{
    printf("Hello world\n");
    return 0;
}

