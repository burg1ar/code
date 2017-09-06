#include"forTest.h"
void reverse_level_order(BiNode* bt){
    if(!bt) return;
    queue<BiNode*> que;
    stack<BiNode*> stk;
    BiNode* tmp;
    que.push(bt);
    while(!que.empty()){
        tmp=que.front();
        stk.push(tmp);
        que.pop();
        if(tmp->lchild)
            que.push(tmp->lchild);
        if(tmp->rchild)
            que.push(tmp->rchild);
    }
    while(!stk.empty()){
        tmp=stk.top();
        cout<<tmp->val<<" ";
        stk.pop();
    }
}
int main() {
    BiNode* bt;
    char arr[]= {'1','#','3','#','#','6','7'};
    build_tree(bt,arr,0,7);
    cout<<"reverse level order:"<<endl;
    reverse_level_order(bt);
    cout<<endl;
    return 0;
}

