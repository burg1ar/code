#include<iostream>
using namespace std;
void swap(int *x,int *y){
    int t=*x;
    *x=*y;
    *y=t;
}
void frontOdd(int arr[],int n){
    int low=0,high=n-1;
    while(low<high){
        if(arr[low]%2==0){
            swap(arr+low,arr+high);
            high--;
        }else{
            low++;
        }
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    cout<<"before ";
    display(arr,9);
    frontOdd(arr,9);
    cout<<"after  ";
    display(arr,9);
    return 0;
}
