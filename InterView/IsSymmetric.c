#include <stdio.h>
typedef struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 }TreeNode ;
bool IsMirror(struct TreeNode *p, struct TreeNode *q) {
    if (p == NULL || q == NULL) {
        if (p == q) {
            return true;
        }
        return false;
    }
    return p->val == q->val && IsMirror(p->left, q->right) && IsMirror(p->right, q->left);
}
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return IsMirror(root->left, root->right);
}
int main()
{
    printf("Hello world\n");
    return 0;
}


