#include"linkedList.h"
#include<cmath>
void del_redundant(LNode* L,int n){
    int count[n+1];
    for(int i=0;i<n+1;++i){
        count[i]=0;
    }
    LNode* pre=L;
    LNode* tmp=NULL;
    L=L->next;
    while(L){
        if(count[abs(L->val)]==0){
            count[abs(L->val)]=1;
            pre=L;
            L=L->next;
        }else{
            tmp=L;
            pre->next=tmp->next;
            L=pre->next;
            free(tmp);
        }
    }
}
int main(){
    int arr[]={21,-15,-15,-7,15};
    LNode* L=NULL;
    L=createList(L,arr,5);
    display(L);
    del_redundant(L,21);
    display(L);
    return 0;
}
