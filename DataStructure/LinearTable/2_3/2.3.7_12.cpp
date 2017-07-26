#include"linkedList.h"
#include<cstring>
#define MAX 100
void unique(LNode* L){
    int cnt[MAX];
    memset(cnt,0,sizeof(cnt));
    LNode* pre=L;
    L=L->next;
    while(L){
        if(cnt[L->val]==0){   //第一次遇到值L->val
            ++cnt[L->val];
            pre=pre->next;
            L=L->next;
        }else{
            pre->next=L->next;  //删除重复元素
            free(L);
            L=pre->next;
        }
    }
}
int main(){
    int arr[]={7,10,10,21,30,42,42,42,51,70};
    LNode* L=NULL;
    L=createList(L,arr,10);
    display(L);
    unique(L);
    display(L);
    return 0;
}
