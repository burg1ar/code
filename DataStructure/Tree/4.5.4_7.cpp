#include"testBST.h"
int level(BST tr,int key){
    if(tr==nullptr)
        return -32768; //ERROR:empty BST
    if(key==tr->val)
        return 1;
    else if(key<tr->val)
        return 1+level(tr->lchild,key);
    else if(key>tr->val)
        return 1+level(tr->rchild,key);
}
int level2(BST tr,int key){
    int level=0;
    while(tr && key!=tr->val){
        if(key<tr->val){
            tr=tr->lchild;
            level++;
        }else{
            tr=tr->rchild;
            level++;
        }
    }
    if(tr!=nullptr)
        return level+1;
    else
        return -1; //ERROR
}
int main(){
    BST tr;
    int arr[]={5,3,6,2,4};
    createBST(tr,arr,5);
    cout<<" level of 5 : "<<level(tr,5)<<endl;
    cout<<"level2 of 5 : "<<level2(tr,5)<<endl;
    cout<<" level of 2 : "<<level(tr,2)<<endl;
    cout<<"level2 of 2 : "<<level2(tr,2)<<endl;
    cout<<"level of 7(not in tr) : "<<level(tr,7)<<endl;
    cout<<"level2 of 7           : "<<level2(tr,7)<<endl;
    cout<<"level of 1(not in tr) : "<<level(tr,1)<<endl;
    cout<<"level2 of 1           : "<<level2(tr,1)<<endl;
    BST tr2=nullptr;
    cout<<level(tr2,1)<<endl;
    return 0;
}
