/*
设有两个集合，A={a_i|a_i<a_i+1,i=1,2,...,n},B={b_j|b_j<b_j+1,j=1,2,...,n}，均存放在单链表中
求A与B的交集，且保存在单链表A中
*/
#include"linkedList.h"
LNode* intersect(LNode* A,LNode* B){
    LNode *p=A->next,*q=B->next;
    A->next=NULL;
    LNode *pnext,*qnext;
    while(p || q){   //程序书写不会冗长，但逻辑判断易读性差
        if(q==NULL || (p && p->val<q->val)){
            pnext=p->next;
            free(p);

            p=pnext;
        }else if(p==NULL || (q && p->val>q->val)){
            qnext=q->next;
            free(q);

            q=qnext;
        }else if(p && q && p->val==q->val){
            pnext=p->next;
            qnext=q->next;

            p->next=A->next;    //只保留一个节点
            A->next=p;
            free(q);

            p=pnext;
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
    intersect(A,B);
    display(A);
    return 0;
}
