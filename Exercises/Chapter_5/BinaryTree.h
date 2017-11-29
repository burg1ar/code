#include<iostream>
#include<cstdlib>
using namespace std;
typedef int ElemType;
typedef struct BTNode{
    ElemType val;
    BTNode *lchild,*rchild;
}BTNode,*BTree;
void makeBTree(BTree &bt,ElemType arr[],int index,int len){
    //9999 means empty node
    if(index>=len || arr[index]==9999) return;
    bt=(BTree)malloc(sizeof(BTNode));
    bt->val=arr[index];
    bt->lchild=bt->rchild=nullptr;
    makeBTree(bt->lchild,arr,2*index+1,len);
    makeBTree(bt->rchild,arr,2*index+2,len);
}
void NLR(BTree T){
    if(T){
        cout<<T->val<<" ";
        NLR(T->lchild);
        NLR(T->rchild);
    }
}
