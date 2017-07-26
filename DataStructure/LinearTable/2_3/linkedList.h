#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
typedef struct LNode{
    int val;
    struct LNode* next;
}LNode;
LNode* createList(LNode* &L,int arr[],int n){
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;

    LNode* p=L;
    LNode* tmp=NULL;
    for(int i=0;i<n;i++){
        tmp=(LNode*)malloc(sizeof(LNode));
        tmp->val=arr[i];
        tmp->next=NULL;

        p->next=tmp;
        p=tmp;
    }
    return L;
}
LNode* createList_head(LNode* &L){
    LNode* tmp=NULL;
    int x;
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    while(scanf("%d",&x)==1){
        tmp=(LNode*)malloc(sizeof(LNode));
        tmp->val=x;
        tmp->next=L->next;
        L->next=tmp;
    }
    return L;
}
LNode* createList_tail(LNode* &L){
    LNode* tmp;
    LNode* tail;
    int x;
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    tail=L;
    while(scanf("%d",&x)==1){
        tmp=(LNode*)malloc(sizeof(LNode));
        tmp->val=x;
        tmp->next=NULL;
        tail->next=tmp;
        tail=tmp;
    }
    return L;
}
LNode* getElem(LNode* L,int i){
    int k=1;
    LNode* p=L->next;
    if(i==0) return L;
    if(i<0) return NULL;
    while(p && k<i){
        p=p->next;
        k++;
    }
    return p;
}
LNode* locateElem(LNode* L,int e){
    LNode* p=L->next;
    while(p && p->val!=e){
        p=p->next;
    }
    return p;
}
void insert(LNode* L,int val,int pos){
    LNode* p=getElem(L,pos-1);
    LNode* tmp=(LNode*)malloc(sizeof(LNode));
    tmp->val=val;

    tmp->next=p->next;
    p->next=tmp;
}
void del(LNode* L,int pos){
    LNode* p=getElem(L,pos-1);
    LNode* q=p->next;
    p->next=q->next;
    free(q);
}
void display(LNode* L){
    cout<<"[head]->";
    L=L->next;
    while(L){
        cout<<"["<<L->val<<"]->";
        L=L->next;
    }
    cout<<"NULL"<<endl;
}


#endif // LINKEDLIST_H_INCLUDED
