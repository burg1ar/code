#include"linkedList.h"
void del_min(LNode* L){
    LNode* pre=L;
    LNode* p=L->next;
    LNode* min_pre=pre;
    LNode* min_p=p;
    while(p){
        if(p->val<min_p->val){
            min_p=p;
            min_pre=pre;
        }
        pre=p;
        p=p->next;
    }
    min_pre->next=min_p->next;
    free(min_p);
}
int main(){
    LNode* L=NULL;
    int arr[]={7,3,4,6,5,2,1,8,9};
    L=createList(L,arr,9);
    del_min(L);
    display(L);
    return 0;
}
