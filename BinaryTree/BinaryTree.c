


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "BinaryTree.h"

                                                      
BNode* CreateNode(TDataType data)              
{                                                     
    BNode *NewNode = (BNode*) malloc (sizeof(BNode));
    assert(NewNode != NULL);
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;
    return NewNode;
}                                                     
                                                                                         
Result CreateTree(TDataType preorder[], int size)      
{   
    TDataType rootValue = preorder[0];   
    Result ret = {NULL, 0};
    Result leftret = {NULL, 0};
    Result rightret = {NULL, 0};
    if(size == 0) {
        Result ret = {NULL, 0};
        return ret;
    }
    if (rootValue == -1) {
        Result ret = {NULL, 1};
        return ret;
    }
    ret.result = CreateNode(rootValue);
    leftret = CreateTree(preorder + 1, size - 1);
    (ret.result)->left = leftret.result;
    rightret = CreateTree(preorder + 1 + leftret.use, size - 1 - leftret.use);
    (ret.result)->right = rightret.result;
    ret.use = 1 + leftret.use + rightret.use;
    return ret;
}

void PreOrderRec(BNode *root)
{
    if (root == NULL) {
        return;
    }    
    printf("%d ", root->data);
    PreOrderRec(root->left);
    PreOrderRec(root->right);
}

void InOrderRec(BNode *root)
{
    if (root == NULL) {
       return; 
    }
    InOrderRec(root->left);
    printf("%d ", root->data);
    InOrderRec(root->right);
}

void PostOrderRec(BNode *root) 
{
    if (root == NULL) {
        return;
    }
    PostOrderRec(root->left);
    PostOrderRec(root->right);
    printf("%d ", root->data);
}


void  BinaryTreeTest()                                
{                                                     
    TDataType preorder[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6 ,7};                         
    int size = sizeof(preorder) / sizeof(preorder[0]);
    BNode *btree = NULL;
    Result result = {NULL, 0};
    result = CreateTree(preorder, size);
    btree = result.result;
    printf("PreOrderRec   :");
    PreOrderRec(btree);
    printf("\n");
    printf("InOrderRec    :");
    InOrderRec(btree);
    printf("\n");
    printf("PostOrderRec  :");
    PostOrderRec(btree);
    printf("\n");
}                      

