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
    display_by_level(bt2);
    return 0;
}

