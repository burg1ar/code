/*
在一维数组A[m+n]中存放这两个线性表(a1,a2,...,am)和(b1,b2,...,bn)
将两个线性表互换位置
*/
#include<iostream>
using namespace std;
void reverse(int arr[],int low,int high,int arrySize){
    if(low>=high || high>=arrySize) return;
    int mid=(low+high)/2;
    for(int i=0;i<=mid-low;i++){
        int tmp=arr[low+i];
        arr[low+i]=arr[high-i];
        arr[high-i]=tmp;
    }
}
void exchange(int arr[],int m,int n,int arrySize){
    reverse(arr,0,m+n-1,arrySize);
    reverse(arr,0,n-1,arrySize);
    reverse(arr,n,m+n-1,arrySize);
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    exchange(arr,5,4,9);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
