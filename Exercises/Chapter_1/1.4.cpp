#include"LinkedList.h"
void rangeDel(LinkedList L,ElemType min,ElemType max){
    LinkedList p,q;
    while(L && L->val<=min){
        p=L;
        L=L->next;
    }
    while(L && L->val<max){
        q=L->next;
        free(L);
        L=q;
    }
    p->next=L;
}
int main(){
    LinkedList L;
    ElemType arr[]={1,2,3,4,5,6,7,8};
    makeList(L,arr,8);
    printList(L);
    rangeDel(L,3,6);
    printList(L);
    return 0;
}
