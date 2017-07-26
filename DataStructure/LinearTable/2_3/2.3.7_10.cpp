#include"linkedList.h"
//使用尾插法建立单链表B
void divide(LNode* A,LNode* &B){
    B=(LNode*)malloc(sizeof(LNode));
    B->next=NULL;
    LNode* tail=B;

    LNode* pre=A;
    LNode* p=A->next;

    int count=0;
    while(p){
        if(++count%2==0){
            pre->next=p->next;  //摘下p
            tail->next=p;
            p->next=NULL;
            tail=p;

            p=pre->next;    //将p重新作为迭代指针
        }else{
            pre=pre->next;
            p=p->next;
        }
    }
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    LNode* A=NULL;
    A=createList(A,arr,10);
    display(A);
    LNode* B=NULL;
    divide(A,B);
    display(A);
    display(B);
    return 0;
}
