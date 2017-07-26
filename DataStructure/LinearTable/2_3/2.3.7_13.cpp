//T(n)=O(lenA+lenB)
#include"linkedList.h"
LNode* mergeList(LNode* A,LNode* B){
    LNode *p=A->next,*q=B->next;
    A->next=NULL;
    LNode *pnext,*qnext;
    while(p && q){
        if(p->val<q->val){
            pnext=p->next;

            p->next=A->next;
            A->next=p;

            p=pnext;
        }else{
            qnext=q->next;

            q->next=A->next;
            A->next=q;

            q=qnext;
        }
    }
    while(p){
        pnext=p->next;

        p->next=A->next;
        A->next=p;

        p=pnext;
    }
    while(q){
        qnext=q->next;

        q->next=A->next;
        A->next=q;

        q=qnext;
    }
    return A;
}
int main(){
    int arr[]={1,2,3,7,9};
    int brr[]={5,8};
    LNode* A=NULL;
    A=createList(A,arr,5);
    LNode* B=NULL;
    B=createList(B,brr,2);
    display(A);
    display(B);
    mergeList(A,B);
    display(A);
    return 0;
}
