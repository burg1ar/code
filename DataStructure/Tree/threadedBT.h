#include<iostream>
#include<cstdlib>
using namespace std;
typedef char ElemType;
typedef struct ThreadedBTNode{
    ElemType val;
    ThreadedBTNode *lchild,*rchild;
    int ltag,rtag;
}ThreadedBTNode,*ThreadedBT;
void makeEmptyThreadTree(ThreadedBT &Thrt,ElemType arr[],int index,int len){
    //not threaded yet
    if(index>=len || arr[index]=='#') return;
    Thrt=(ThreadedBT)malloc(sizeof(ThreadedBTNode));
    Thrt->val=arr[index];
    Thrt->lchild=Thrt->rchild=nullptr;

    makeEmptyThreadTree(Thrt->lchild,arr,2*index+1,len);
    makeEmptyThreadTree(Thrt->rchild,arr,2*index+2,len);
}
void inOrderThread(ThreadedBT &p,ThreadedBT &pre){
    if(p){
        inOrderThread(p->lchild,pre);
        if(p->lchild==nullptr){
            p->lchild=pre;
            p->ltag=1;
        }
        if(pre!=nullptr && pre->rchild==nullptr){
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
        inOrderThread(p->rchild,pre);
    }
}
void createInOrderThread(ThreadedBT T){
    ThreadedBT pre=nullptr;
    if(T){
        inOrderThread(T,pre);
        pre->rchild=nullptr;
        pre->rtag=1;
    }
}
ThreadedBTNode *firstNode(ThreadedBTNode *p){
    while(p->ltag==0) p=p->lchild;
    return p;
}
ThreadedBTNode *nextNode(ThreadedBTNode *p){
    if(p->rtag==0)
        return firstNode(p->rchild);
    else
        return p->rchild;
}
void inOrderThreadTraverse(ThreadedBT T){
    for(ThreadedBTNode *p=firstNode(T);p!=nullptr;p=nextNode(p))
        cout<<p->val<<" ";
    cout<<endl;
}
void inOrderThreadTraverse2(ThreadedBT T){
    if(T){
        while(T->lchild) T=T->lchild;
        cout<<T->val<<" ";
        while(T->rchild){
            T=T->rchild;
            cout<<T->val<<" ";
        }
    }
    cout<<endl;
}
void inOrderTraverse(ThreadedBT T){
    if(T){
        inOrderTraverse(T->lchild);
        cout<<T->val<<" ";
        inOrderTraverse(T->rchild);
    }
}
