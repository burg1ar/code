#include<iostream>
#include<cstdlib>
using namespace std;
typedef char ElemType;
typedef struct BTNode{
    ElemType val;
    BTNode *lchild,*rchild;
}BTNode,*BTree;
void makeBTree(BTree &bt,ElemType arr[],int index,int len){
    if(index>=len || arr[index]=='#') return;
    bt=(BTree)malloc(sizeof(BTNode));
    bt->val=arr[index];
    bt->lchild=bt->rchild=nullptr;
    makeBTree(bt->lchild,arr,2*index+1,len);
    makeBTree(bt->rchild,arr,2*index+2,len);
}

