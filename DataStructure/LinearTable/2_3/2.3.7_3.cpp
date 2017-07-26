#include "linkedList.h"
#include<stack>
void display_r1(LNode* L){
    stack<int> stk;
    L=L->next;
    while(L){
        stk.push(L->val);
        L=L->next;
    }
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
}
void display_r2(LNode* L){
    if(L->next){
        display_r2(L->next);
    }
    cout<<L->val<<" ";
}
int main(){
    LNode* L=NULL;
    int arr[]={1,2,3,4,5};
    L=createList(L,arr,5);
    display_r2(L);
    return 0;
}
