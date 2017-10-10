#include"forTest.h"
//assuming "p" is at the left of "q"
BiNode* comm_ancestor(BiNode* root,BiNode* p,BiNode* q){
    stack<BiNode*> stk;
    queue<BiNode*> que;
    BiNode* curr=bt;
    BiNode* preVisited=nullptr;
    while(curr || !stk.empty()){
        while(curr){
            stk.push(curr);
            curr=curr->lchild;
        }
        curr=stk.top();
        if(curr==p){

        }
    }
}
