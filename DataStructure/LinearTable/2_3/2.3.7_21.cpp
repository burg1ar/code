#include"linkedList.h"
int getLen(LNode* L){
    int len=0;
    while(L){
        ++len;
        L=L->next;
    }
    return len;
}
LNode* find_k(LNode* L,int k){
    L=L->next;
    int len=getLen(L);
    if(L==NULL) return NULL;
    if(k>len) return NULL;
    for(int i=1;i<len-k+1;++i){
        L=L->next;
    }
    cout<<L->val<<endl;
    return L;
}
int main(){
    int arr[]={1,2,3,4,5};
    LNode* L=NULL;
    L=createList(L,arr,5);
    display(L);
    find_k(L,2);
    return 0;
}
