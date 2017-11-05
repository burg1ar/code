#include"LinkedList.h"
void func(LinkedList la,LinkedList lb){
    LinkedList p=la->next,q=lb->next;
    LinkedList prior=la;
    LinkedList it,tmp;
    while(q){
        it=p;
        while(it && it->val<=q->val){
            prior=it;
            it=it->next;
        }
        tmp=q->next;
        if(it==p){
            q->next=la->next;
            la->next=q;
        }else if(it==nullptr){
            prior->next=q;
            q->next=nullptr;
        }else{
            q->next=prior->next;
            prior->next=q;
        }
        p=q;
        q=tmp;
    }
}
int main(){
    LinkedList la,lb;
    ElemType A[]={1,5,8,9,15};
    ElemType B[]={2,3,6,8,15,18};
    makeList(la,A,5);
    cout<<"A:"<<endl;
    printList(la);
    makeList(lb,B,6);
    cout<<"B:"<<endl;
    printList(lb);
    func(la,lb);
    printList(la);
    return 0;
}
