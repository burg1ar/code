#include"linkedList.h"
#include<cmath>
void del_redundant(LNode* L,int n){
    int count[n+1];
    for(int i=0;i<n+1;++i){
        count[i]=0;
    }
    LNode* p=NULL;  //p表示待删除节点
    while(L->next){
    //使用L->next作为循环条件，便于找到待删除节点的前驱，L就是待删除节点L->next的前驱
        if(count[abs(L->next->val)]==0){
            count[abs(L->next->val)]=1;
            L=L->next;  //若用while(L)作为循环条件，该出会出现segmentation fault
        }else{
            p=L->next;
            L->next=p->next;
            free(p);
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
