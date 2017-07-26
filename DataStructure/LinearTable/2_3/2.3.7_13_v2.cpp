//T(n)=O(lenA+lenB)
#include"linkedList.h"
LNode* mergeList(LNode* A,LNode* B){
    LNode *p=A->next,*q=B->next;
    A->next=NULL;
    LNode *pnext,*qnext;
    while(p || q){
        if(q==NULL || (p && p->val<q->val)){
            pnext=p->next;

            p->next=A->next;
            A->next=p;

            p=pnext;
        }else if(p==NULL || (q && p->val>=q->val)){
            qnext=q->next;

            q->next=A->next;
            A->next=q;

            q=qnext;
        }
    }
    return A;
}
int main(){
    int arr[]={3,6,8};
    int brr[]={1,3,4,5,8};
    LNode* A=NULL;
    A=createList(A,arr,3);
    LNode* B=NULL;
    B=createList(B,brr,5);
    display(A);
    display(B);
    mergeList(A,B);
    display(A);
    return 0;
}
