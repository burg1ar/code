#include<iostream>
#include<cstdlib>
typedef int ElemType;
using namespace std;
typedef struct LNode{
    ElemType val;
    LNode *next;
}LNode,*LinkedList;
bool makeList(LinkedList &p,ElemType arr[],int n){
    p=(LinkedList)malloc(sizeof(LNode));
    p->val=0;
    p->next=nullptr;
    LinkedList t,q=p;
    for(int i=0;i<n;++i){
        t=(LinkedList)malloc(sizeof(LNode));
        t->val=arr[i];
        t->next=nullptr;

        q->next=t;
        q=t;
    }
    return true;
}
template <typename T>
void printList(T p){
    p=p->next;
    while(p){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}
typedef struct DLNode{
    ElemType val;
    DLNode *prior,*next;
    int freq;
}DLNode,*DLinkedList;
void makeDList(DLinkedList &p,ElemType arr[],int n){
    p=(DLinkedList)malloc(sizeof(DLNode));
    p->val=p->freq=0;
    p->prior=p->next=nullptr;
    DLinkedList t,tail=p;
    for(int i=0;i<n;++i){
        t=(DLinkedList)malloc(sizeof(DLNode));
        t->val=arr[i];
        t->freq=0;

        t->prior=tail;
        t->next=nullptr;

        tail->next=t;
        tail=t;
    }
}
void printFreq(DLinkedList p){
    p=p->next;
    while(p){
        cout<<p->freq<<" ";
        p=p->next;
    }
    cout<<endl;
}
