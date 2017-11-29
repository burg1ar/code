#include"BinaryTree.h"
#include<climits>
bool isBSTUtil(BTree T,int min,int max){
    if(T==nullptr) return true;
    if(T->val<min || T->val>max)
        return 0;
    return
        isBSTUtil(T->lchild, min, T->val-1) && isBSTUtil(T->rchild, T->val+1, max);
}
bool isBST(BTree T){
    return isBSTUtil(T,INT_MIN,INT_MAX);
}
int max(BTree T){
    if(T==nullptr){
        return INT_MIN;
    }else{
        while(T->rchild) T=T->rchild;
        return T->val;
    }
}
int min(BTree T){
    if(T==nullptr){
        return INT_MAX;
    }else{
        while(T->lchild) T=T->lchild;
        return T->val;
    }
}

bool isBST2(BTree T){
    if(T==nullptr) return true;
    if(isBST2(T->lchild)&&isBST2(T->rchild)){
        int m=max(T->lchild);
        int n=min(T->rchild);
        return T->val>m && T->val<n;
    }else{
        return false;
    }
}
//using In-Order Traversal
bool isBST3(BTree T){
    static BTree pre=nullptr;
    if(T){
        if(!isBST3(T->lchild))
            return false;
        if(pre && T->val<pre->val)
            return false;
        pre=T;
        return isBST3(T->rchild);
    }
    return true;
}
int main(){
    BTree T;
    int arr1[]={8,6,10,5,7,9999,11};
    BTree F;
    int arr2[]={8,10,6,5,7,9999,11};
    makeBTree(T,arr1,0,7);
    makeBTree(F,arr2,0,7);
    cout<<"T is BST : "<<isBST(T)<<endl;
    cout<<"F is BST : "<<isBST(F)<<endl;
    cout<<"T is BST2 : "<<isBST2(T)<<endl;
    cout<<"F is BST2 : "<<isBST2(F)<<endl;
    cout<<"T is BST3 : "<<isBST3(T)<<endl;
    cout<<"F is BST3 : "<<isBST3(F)<<endl;
    return 0;
}
