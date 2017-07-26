#include<iostream>
using namespace std;
void reverse(int arr[],int low,int high){
    int mid,tmp;
    mid=(low+high)/2;
    for(int i=0;i<=mid-low;i++){
        tmp=arr[low+i];
        arr[low+i]=arr[high-i];
        arr[high-i]=tmp;
    }
}
void rotate(int arr[],int p,int n){
    reverse(arr,0,n-1);
    reverse(arr,0,p-1);
    reverse(arr,p,n-1);
}
int main(){
    int arr[]={1,2,3,4,5,6,7};
    rotate(arr,3,7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
