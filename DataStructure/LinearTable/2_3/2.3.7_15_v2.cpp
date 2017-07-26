//T(n)=O(lenA+lenB)
#include"linkedList.h"
LNode* intersect(LNode* A,LNode* B){
    LNode *p=A->next,*q=B->next;
    A->next=NULL;
    LNode *pnext,*qnext;
    while(p && q){  //逻辑清晰，但代码冗余
        if(p->val<q->val){
            pnext=p->next;
            free(p);
            p=pnext;
        }else if(p->val>q->val){
            qnext=q->next;
            free(q);
            q=qnext;
        }else{
            pnext=p->next;
            qnext=q->next;

            p->next=A->next;    //只保留一个节点
            A->next=p;
            free(q);

            p=pnext;
            q=qnext;
        }
    }
    while(p){
        pnext=p->next;
        free(p);
        p=pnext;
    }
    while(q){
        qnext=q->next;
        free(q);
        q=qnext;
    }
    return A;
}
int main(){
    int arr[]={1,4,6,7,8};
    int brr[]={1,3,4,5,6,8};
    LNode* A=NULL;
    A=createList(A,arr,3);
    LNode* B=NULL;
    B=createList(B,brr,5);
    display(A);
    display(B);
    intersect(A,B);
    display(A);
    return 0;
}
