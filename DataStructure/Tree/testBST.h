#include"bst.h"
BSTNode* search(BST tr,elemType key){
    while(tr!=nullptr && tr->val!=key){
        if(key<tr->val)
            tr=tr->lchild;
        else
            tr=tr->rchild;
    }
    return tr;
}
BSTNode* find(BST tr,elemType key){
    if(tr==nullptr)
        return nullptr;
    if(key<tr->val){
        return find(tr->lchild,key);
    }else if(key>tr->val){
        return find(tr->rchild,key);
    }else{
        return tr;
    }
}
BSTNode* findMin(BST tr){
    if(tr==nullptr)
        return nullptr;
    else if(tr->lchild==nullptr)
        return tr;
    else
        return findMin(tr->lchild);
}//recursive implementation
BSTNode* findMax(BST tr){
    if(tr)
        while(tr->rchild)
            tr=tr->rchild;
    return tr;
}//non-recursive implementation
bool insert(BST &tr,elemType key){
    if(tr==nullptr){
        tr=(BST)malloc(sizeof(BSTNode));
        tr->val=key;
        tr->lchild=tr->rchild=nullptr;
        return true;
    }else if(key==tr->val){
        return false;
    }else if(key<tr->val){
        return insert(tr->lchild,key);
    }else{
        return insert(tr->rchild,key);
    }
}
void createBST(BST &tr,elemType arr[],int n){
    tr=nullptr;
    for(int i=0;i<n;i++){
        insert(tr,arr[i]);
    }
}
void inOrder(BST tr){
    if(tr){
        inOrder(tr->lchild);
        cout<<tr->val<<" ";
        inOrder(tr->rchild);
    }
}
