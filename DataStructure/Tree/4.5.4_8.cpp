#include"testBST.h"
int depth(BST tr){
    if(tr==nullptr)
        return 0;
    int lDepth=depth(tr->lchild);
    int rDepth=depth(tr->rchild);
    return lDepth>rDepth?1+lDepth:1+rDepth;
}
bool isBalance(BST tr){
    if(tr==nullptr) return true;
    int factor=depth(tr->lchild)-depth(tr->rchild);
    if(factor>1 || factor<-1) return false;
    return isBalance(tr->lchild) && isBalance(tr->rchild);
}
int main(){
    BST tr1;
    int arr1[]={1,2,3,4,5};
    createBST(tr1,arr1,5);
    BST tr2;
    int arr2[]={5,3,6,2,4};
    createBST(tr2,arr2,5);
    inOrder(tr1);
    cout<<endl;
    cout<<"isBalance : "<<isBalance(tr1)<<endl;
    inOrder(tr2);
    cout<<endl;
    cout<<"isBalance : "<<isBalance(tr2)<<endl;
    return 0;
}
