#include"LinkedList.h"
LinkedList Union(LinkedList la,LinkedList lb){
    LinkedList pa=la->next;
    LinkedList pb=lb->next;
    LinkedList pc=la;
    LinkedList u;
    while(pa && pb){
        if(pa->val<pb->val){
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }else if(pa->val>pb->val){
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }else{
            pc->next=pa;
            pc=pa;
            pa=pa->next;
            u=pb;
            pb=pb->next;
            free(u);
        }
    }
    if(pa) pc->next=pa;
    else pc->next=pb;
    free(lb);
    return la;
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
    Union(la,lb);
    printList(la);
    return 0;
}
