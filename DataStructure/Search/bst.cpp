#include"bst.h"
#include<cstdlib>
#include<iostream>
using namespace std;
struct BSTNode{
    ElemType val;
    BST lchild;
    BST rchild;
};
BST Insert(BST &T,ElemType X){
    if(T==nullptr){
        T=(BSTNode*)malloc(sizeof(BSTNode));
        T->val=X;
        T->lchild=T->rchild=nullptr;
    }else if(X<T->val){
        T->lchild=Insert(T->lchild,X);
    }else if(X>T->val){
        T->rchild=Insert(T->rchild,X);
    }
    return T;
}
void creatBST(BST &T,ElemType arr[],int n){
    for(int i=0;i<n;++i)
        Insert(T,arr[i]);
}
Position FindMin(BST T){
    if(T==nullptr) return nullptr;
    while(T->lchild)
        T=T->lchild;
    return T;
}
Position FindMax(BST T){
    if(T==nullptr) return nullptr;
    while(T->rchild) T=T->rchild;
    return T;
}
BST Delete(BST &T,ElemType X){
    Position tmpCell;
    if(T==nullptr){
        return nullptr; //ERROR
    }else if(X<T->val){
        T->lchild=Delete(T->lchild,X);
    }else if(X>T->val){
        T->rchild=Delete(T->rchild,X);
    }else if(T->lchild && T->rchild){
        tmpCell=FindMin(T->rchild);
        T->val=tmpCell->val;
        T->rchild=Delete(T->rchild,T->val);
    }else{
        tmpCell=T;
        if(T->lchild==nullptr)
            T=T->rchild;
        else if(T->rchild==nullptr)
            T=T->lchild;
        free(tmpCell);
    }
    return T;
}
void printInOrder(BST T){
    if(T){
        printInOrder(T->lchild);
        cout<<T->val<<" ";
        printInOrder(T->rchild);
    }
}
int main(){
    BST T=nullptr;
    int arr[]={8,6,10,5,7,11};
    creatBST(T,arr,6);
    printInOrder(T);
    cout<<endl;
    Delete(T,8);
    printInOrder(T);
    cout<<endl;
    return 0;
}
