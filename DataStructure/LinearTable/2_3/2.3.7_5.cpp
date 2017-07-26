#include"linkedList.h"
void revert_1(LNode* L){
//就地转置单链表(头插法)
    LNode* p=L->next;
    LNode* q=NULL;
    L->next=NULL;
    while(p){
        q=p->next;

        p->next=L->next;
        L->next=p;

        p=q;
    }
}
void revert_2(LNode* L){
//反转指针

}
int main(){
    LNode* L=NULL;
    int arr[]={1,2,3,4,5};
    L=createList(L,arr,5);
    display(L);
    revert_2(L);
    display(L);
    return 0;
}
