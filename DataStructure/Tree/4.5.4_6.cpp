#include"testBST.h"
bool isBST(BST tr){
    if(tr==nullptr){
        return true;
    }else if(tr->lchild){
        if(tr->lchild->val<tr->val)
            return isBST(tr->lchild);
        else
            return false;
    }else if(tr->rchild){
        if(tr->rchild->val>tr->val)
            return isBST(tr->rchild);
        else
            return false;
    }else{
        return true;
    }
}
int main(){
    BST tr;
    int arr[]={5,3,6,2,4};
    createBST(tr,arr,5);
    inOrder(tr);
    cout<<endl;
    cout<<isBST(tr)<<endl;
    tr->lchild->val=7;
    inOrder(tr);
    cout<<endl;
    cout<<isBST(tr)<<endl;
    BST tr2=nullptr;
    cout<<isBST(tr2)<<endl;
    BST tr3=(BST)malloc(sizeof(BSTNode));
    tr3->val=1;
    tr3->lchild=tr3->rchild=nullptr;
    cout<<isBST(tr3)<<endl;
    return 0;
}
