#include"forTest.h"
elemType pre_k(BiNode* bt,int k){
    stack<BiNode*> stk;
    int count=0;
    while(bt || !stk.empty()){
        while(bt){
            if(++count==k) return bt->val;
            stk.push(bt);
            bt=bt->lchild;
        }
        if(!stk.empty()){
            bt=stk.top();
            stk.pop();
            bt=bt->rchild;
        }
    }
    return '#'; //ERROR
}
int main(){
    BiNode* bt;
    elemType arr[]={'1','2','3','4','5'};
    build_tree(bt,arr,0,5);
    preOrder(bt);
    cout<<endl;
    cout<<"4 th: "<<pre_k(bt,4)<<endl;
    return 0;
}
