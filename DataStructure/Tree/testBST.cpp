#include"testBST.h"
int main(){
    BST tr=nullptr;
    int arr[]={1,2,3,4,5};
    createBST(tr,arr,5);
    cout<<"BST:"<<endl;
    inOrder(tr);
    cout<<endl;
    cout<<"search for 3: "<<search(tr,3)->val<<endl;
    cout<<"find 2: "<<find(tr,2)->val<<endl;
    cout<<"find min: "<<findMin(tr)->val<<endl;
    cout<<"find max: "<<findMax(tr)->val<<endl;
    insert(tr,7);
    cout<<"after inserting 7"<<endl;
    inOrder(tr);
    cout<<endl;
    return 0;
}
