#include"LinkedList.h"
//this algorithm is a buggy one!
DLinkedList locate(DLinkedList L,ElemType x){
    DLinkedList p=L->next,q;
    while(p && p->val!=x) p=p->next;
    if(!p) return p;
    p->freq++;
    //if p is the last node
    //the following two statements will cause a segmentation fault !!!
    p->next->prior=p->prior;
    p->prior->next=p->next;
    q=p->prior;
    while(q!=L && q->freq<p->freq) q=q->prior;

    p->next=q->next;
    q->next->prior=p;
    p->prior=q;
    q->next=p;

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
