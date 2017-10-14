#include"testBST.h"
void bigger_k(BST tr,int key){
    if(tr==nullptr) return;
    if(tr->rchild)
        bigger_k(tr->rchild,key);
    if(tr->val>=key)
        cout<<tr->val<<" ";
    if(tr->lchild)
        bigger_k(tr->lchild,key);
}
int main(){
    BST tr;
    int arr[]={5,3,6,2,4};
    createBST(tr,arr,5);
    inOrder(tr);
    cout<<endl;
    bigger_k(tr,4);
    cout<<endl;
    return 0;
}
