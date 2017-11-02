#include"LinkedList.h"
DLinkedList locate(DLinkedList L,ElemType x){
    DLinkedList p=L,q;
    while(p && p->val!=x) p=p->next;
    if(p){
        (p->freq)++;
        q=L->next;
        while(q->next && p->freq<q->freq) q=q->next;
        if(q==p){
            return p;
        }else{
            if(p->next==nullptr){ //if p is last node
                p->prior->next=nullptr;
            }else{
                p->prior->next=p->next;
                p->next->prior=p->prior;
            }
            if(q->next==nullptr){
                q->next=p;
                p->prior=q;
                p->next=nullptr;
            }else{
                p->next=q;
                p->prior=q->prior;

                q->prior->next=p;
                q->prior=p;
            }
        }
    }
    return p;
}
int main(){
    DLinkedList L;
    ElemType arr[]={1,2,3,4,5,6,7};
    makeDList(L,arr,7);
    printList(L);
    ElemType x;
    cout<<"input x"<<endl;
    while(cin>>x){
        cout<<"locate"<<x<<endl;
        locate(L,x);
        printList(L);
        printFreq(L);
    }
    return 0;
}
