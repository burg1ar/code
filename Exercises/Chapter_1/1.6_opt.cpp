#include"LinkedList.h"
DLinkedList locate(DLinkedList L,ElemType x){
    DLinkedList p=L,q;
    while(p && p->val!=x) p=p->next;
    if(p){
        (p->freq)++;
        q=p->prior;
        while(q!=L && p->freq>q->freq) q=q->prior;
        if(q==p->prior) return p; //bug fix:if all the previous freq>=p->freq
        //p should stay where it is
        if(p->next==nullptr){
            p->prior->next=nullptr;
        }else{
            p->next->prior=p->prior;
            p->prior->next=p->next;
        }
        p->next=q->next;
        q->next->prior=p;
        p->prior=q;
        q->next=p;
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
