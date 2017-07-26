#include"linkedList.h"
//关键是要找到第 n-k+1 个节点，即为倒数第 k 个节点
//设置双指针 p 和 q，初始都指向第一个节点（头结点下一个节点）
//p先走到第 k 位置，p剩余 n-k+1 个位置走到尽头
//此时 q 开始同 p 同步移动，当 p 走到尽头时，q 即指向倒数第 k 个节点
LNode* find_k(LNode* L,int k){
    LNode* p=L->next;
    LNode* q=p;
    if(k<1) return NULL;
    for(int i=1;i<=k;++i){
        p=p->next;
    }
    while(p){
        p=p->next;
        q=q->next;
    }
    cout<<q->val<<endl;
    return q;
}
int main(){
    int arr[]={1,2,3,4,5};
    LNode* L=NULL;
    L=createList(L,arr,5);
    display(L);
    find_k(L,1);
    return 0;
}
