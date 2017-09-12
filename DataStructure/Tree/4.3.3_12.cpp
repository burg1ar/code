#include"forTest.h"
void ancestor_x(BiNode* bt,elemType x){
    stack<BiNode*> stk;
    BiNode* curr=bt;
    BiNode* preVisited=nullptr;
    while(curr || !stk.empty()){
        while(curr){
            stk.push(curr);
            curr=curr->lchild;
        }
        curr=stk.top();
        if(curr->val==x){
            stk.pop();
            while(!stk.empty()){
                cout<<stk.top()->val<<" ";
                stk.pop();
            }
            return;
        }
        if(curr->rchild==nullptr || curr->rchild==preVisited){
            stk.pop();
            preVisited=curr;
            curr=nullptr;
        }else{
            curr=curr->rchild;
        }
    }
}
int main(){
    BiNode* bt;
    elemType arr[]={'1','2','3','#','#','4','5','#','#','#','#','7'};
    build_tree(bt,arr,0,12);
    display_by_level(bt);
    cout<<"ancestor_x(bt,'7')"<<endl;
    ancestor_x(bt,'7');
    cout<<endl;
    cout<<"ancestor_x(bt,'5')"<<endl;
    ancestor_x(bt,'5');
    cout<<endl;
    cout<<"ancestor_x(bt,'2')"<<endl;
    ancestor_x(bt,'2');
    cout<<endl;
    cout<<"ancestor_x(bt,'1')"<<endl;
    ancestor_x(bt,'1');
    cout<<endl;
    return 0;
}
