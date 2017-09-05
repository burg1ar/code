#include "binaryTree.h"
void init(BiNode* &bt) {
    bt=nullptr;
}
void complete_tree(BiNode* &bt,elemType arr[],int index,int len) {
    if(index>=len) return;
    bt=(BiNode*)malloc(sizeof(BiNode));
    bt->val=arr[index];
    bt->lchild=bt->rchild=nullptr;
    complete_tree(bt->lchild,arr,2*index+1,len);
    complete_tree(bt->rchild,arr,2*index+2,len);
}
void build_tree(BiNode* &bt,elemType arr[],int index,int len) {
    //'#' represents nullptr
    if(index>=len || arr[index]=='#') return;
    bt=(BiNode*)malloc(sizeof(BiNode));
    bt->val=arr[index];
    bt->lchild=bt->rchild=nullptr;
    build_tree(bt->lchild,arr,2*index+1,len);
    build_tree(bt->rchild,arr,2*index+2,len);
}
void preOrder(BiNode* bt) {
    if(bt) {
        cout<<bt->val<<" ";
        preOrder(bt->lchild);
        preOrder(bt->rchild);
    }
}
void inOrder(BiNode* bt){
    if(bt){
        inOrder(bt->lchild);
        cout<<bt->val<<" ";
        inOrder(bt->rchild);
    }
}
void postOrder(BiNode* bt){
    if(bt){
        postOrder(bt->lchild);
        postOrder(bt->rchild);
        cout<<bt->val<<" ";
    }
}
void preOrder_non_recursive(BiNode* bt){
    stack<BiNode*> stk;
    while(bt || !stk.empty()){
        while(bt){
            cout<<bt->val<<" ";
            stk.push(bt);
            bt=bt->lchild;
        }
        if(!stk.empty()){
            bt=stk.top();
            stk.pop();
            bt=bt->rchild;
        }
    }
}
void inOrder_non_recursive(BiNode* bt){
    stack<BiNode*> stk;
    while(bt || !stk.empty()){
        while(bt){
            stk.push(bt);
            bt=bt->lchild;
        }
        if(!stk.empty()){
            bt=stk.top();
            cout<<bt->val<<" ";
            stk.pop();
            bt=bt->rchild;
        }
    }
}
void postOrder_non_recursive(BiNode* bt){
    stack<BiNode*> stk;
    BiNode* curr=bt;
    BiNode* preVisited=nullptr;
    while(curr || !stk.empty()){
        while(curr){
            stk.push(curr);
            curr=curr->lchild;
        }
        curr=stk.top();
        if(curr->rchild==nullptr || curr->rchild==preVisited){
            cout<<curr->val<<" ";
            stk.pop();
            preVisited=curr;
            curr=nullptr;
        }else{
            curr=curr->rchild;
        }
    }
}
void levelOrder(BiNode* bt){
    if(!bt) return;
    queue<BiNode*> que;
    BiNode* tmp;
    que.push(bt);
    while(!que.empty()){
        tmp=que.front();
        cout<<tmp->val<<" ";
        que.pop();
        if(tmp->lchild)
            que.push(tmp->lchild);
        if(tmp->rchild)
            que.push(tmp->rchild);
    }
}
void display_by_level(BiNode* bt) {
    if(!bt) return;
    queue<BiNode*> que;
    que.push(bt);
    BiNode* tmp;
    int curr_level_num=1;
    int next_level_num=0;
    while(!que.empty()) {
        tmp=que.front();
        cout<<tmp->val<<" ";
        que.pop();
        curr_level_num--;
        if(tmp->lchild) {
            que.push(tmp->lchild);
            next_level_num++;
        }
        if(tmp->rchild) {
            que.push(tmp->rchild);
            next_level_num++;
        }
        if(curr_level_num==0) {
            cout<<endl;
            curr_level_num=next_level_num;
            next_level_num=0;
        }
    }
}
int main() {
    BiNode* bt;
    char arr[]= {'1','2','3','4','5'};
    complete_tree(bt,arr,0,5);
    preOrder(bt);
    cout<<endl;

    BiNode* bt2;
    char arr2[]= {'1','#','3','#','#','6','7'};
    build_tree(bt2,arr2,0,7);
    cout<<"display_by_level:"<<endl;
    display_by_level(bt2);

    cout<<"preOrder:"<<endl;
    preOrder(bt2);
    cout<<endl;

    cout<<"preOrder_non_recursive:"<<endl;
    preOrder_non_recursive(bt2);
    cout<<endl;

    cout<<"inOrder:"<<endl;
    inOrder(bt2);
    cout<<endl;

    cout<<"inOrder_non_recursive:"<<endl;
    inOrder_non_recursive(bt2);
    cout<<endl;

    cout<<"postOrder:"<<endl;
    postOrder(bt2);
    cout<<endl;

    cout<<"postOrder_non_recursive:"<<endl;
    postOrder_non_recursive(bt2);
    cout<<endl;

    cout<<"levelOrder:"<<endl;
    levelOrder(bt2);
    cout<<endl;
    return 0;
}

