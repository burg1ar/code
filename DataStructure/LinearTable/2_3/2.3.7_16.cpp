#include<iostream>
#include"linkedList.h"
using namespace std;
bool isSubsequence(LNode* A,LNode* B){
    LNode* p=A->next;
    LNode* q=B->next;
    LNode* tag=p;   //the starting pointer in every turn
    while(p && q){
        if(p->val==q->val){
            p=p->next;
            q=q->next;
        }else{
            tag=tag->next;
            p=tag;
            q=B->next;
        }
    }
    if(q==NULL) return true;
    else return false;
}
int main(){
    LNode* p=NULL;
    LNode* q=NULL;
    p=createList_tail(p);
    display(p);
    q=createList_tail(q);
    display(q);
    cout<<isSubsequence(p,q)<<endl;
    return 0;
}
