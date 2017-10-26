#include<iostream>
using namespace std;
int search_seq(int arr[],int n,int key){
    int i;
    for(i=0;i<n && arr[i]!=key;i++);
    if(i==n) return -1;
    return i;
}
int search_sorted_seq(int arr[],int n,int key){
    int i;
    for(i=0;i<n && arr[i]<key;i++);
    if(i<n && arr[i]==key)
        return i;
    else if(i-1<n && arr[i-1]==key)
        return i-1;
    else
        return -1;
}
int main(){
    int arr[]={1,2,3,5,8,13,21};
    cout<<search_seq(arr,7,8)<<endl;
    cout<<search_seq(arr,7,7)<<endl;
    cout<<search_sorted_seq(arr,7,8)<<endl;
    cout<<search_sorted_seq(arr,7,7)<<endl;
    return 0;
}
