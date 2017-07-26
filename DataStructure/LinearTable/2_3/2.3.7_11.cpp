#include"linkedList.h"
//使用头插法建立B，不设计数器count
LNode* divide(LNode* A){
    LNode* B=(LNode*)malloc(sizeof(LNode));
    B->next=NULL;

    LNode* pre=A;
    LNode* p=A->next;

    while(p){
        pre=p;
        p=p->next;  //移动到待摘除节点

        pre->next=p->next;  //摘除节点p
        //头插法建立单链表B
        p->next=B->next;
        B->next=p;

        p=pre->next;    //p重新作为迭代指针
    }
    return B;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    LNode* A=NULL;
    A=createList(A,arr,10);
    display(A);
    LNode* B=NULL;
    B=divide(A);
    display(A);
    display(B);
    return 0;
}
