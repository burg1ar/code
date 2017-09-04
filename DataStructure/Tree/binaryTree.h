#include<iostream>
#include<cstdlib>
#include<queue>
#define elemType char
using namespace std;
typedef struct BiNode{
    elemType val;
    BiNode* lchild;
    BiNode* rchild;
}BiNode;
void init(BiNode* &bt);
void complete_tree(BiNode* &bt,elemType arr[],int index,int len);
void build_tree(BiNode* &bt,elemType arr[],int index,int len);
void preOder(BiNode* bt);
void inOrder(BiNode* bt);
void display_by_level(BiNode* bt);
