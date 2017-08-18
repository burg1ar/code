#include<iostream>
using namespace std;
bool is_max_heap(int arr[],int n){
    int lchild,rchild;
    for(int i=0;i<n;i++){
        lchild=2*i+1;rchild=2*i+2;
        if(lchild<n && rchild<n){
            if(arr[i]<arr[lchild] || arr[i]<arr[rchild])
                return false;
        }else if(lchild<n && rchild>=n){
            if(arr[i]<arr[lchild])
                return false;
        }
    }
    return true;
}
int main(){
    cout<<"input an array of size 10:"<<endl;
    int arr[10];
    for(int i=0;i<10;i++){
        cin>>arr[i];
        cout<<arr[i]<<" ";
    }
    cout<<"is max heap ? "<<is_max_heap(arr,10)<<endl;
    return 0;
}
