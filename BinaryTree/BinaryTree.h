#pragma once


typedef int TDataType;

typedef struct BNode{
    TDataType data;
    struct BNode *left;
    struct BNode *right;

} BNode;

typedef struct Result {
    BNode *result;
    int use;
}Result;


Result CreateTree(TDataType preorder[], int size);  //创建树
void PreOrderRec(BNode *root);          //先序遍历
void BinaryTreeTest();     //测试
