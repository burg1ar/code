#include "linkedList.h"
void del_x(LNode* L,int m,int n){
    LNode* pre=L;
    L=L->next;
    while(L){
        if(L->val>m && L->val<n){
            pre->next=L->next;
            free(L);
            L=pre->next;
        }else{
            pre=L;
            L=L->next;
        }
    }
}
int main(){
    int arr[]={1,2,3,4,2,5,6,2,2,7};
    LNode* L=NULL;
    L=createList(L,arr,10);
    display(L);
    del_x(L,1,5);
    display(L);
    return 0;
}
