#include"linkedList.h"
//单链表选择排序
void ascend(LNode* L){
    LNode *p,*pre,*minp,*minpre;
    while(L->next){ //循环直至只剩头结点
        minp=L->next;
        minpre=L;

        LNode* pre=minp;
        LNode* p=minp->next;

        while(p){
            if(p->val<minp->val){
                minpre=pre;
                minp=p;
            }
            pre=p;
            p=p->next;
        }
        cout<<minp->val<<" ";
        minpre->next=minp->next;    //删除最小节点
        free(minp);
    }
}
int main(){
    int arr[]={3,7,4,1,2,5,6};
    LNode* L=NULL;
    L=createList(L,arr,7);
    display(L);
    ascend(L);
    return 0;
}

