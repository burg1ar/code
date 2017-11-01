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
void printList(LinkedList p){
    p=p->next;
    while(p){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}
