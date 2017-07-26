#include<iostream>
using namespace std;
void merge(int arr1[],int arr2[],int n,int arr[]){
    int i=0,j=0,k=0;
    while(i<n && j<n){
        if(arr1[i]<arr2[j]){
            arr[k++]=arr1[i++];
        }else{
            arr[k++]=arr2[j++];
        }
    }
    while(i<n){
        arr[k++]=arr1[i++];
    }
    while(j<n){
        arr[k++]=arr2[j++];
    }
}
int median(int arr1[],int arr2[],int n,int arr[]){
    merge(arr1,arr2,n,arr);
    return arr[n-1];
}
int main(){
    int arr1[]={11,13,15,17,19};
    int arr2[]={2,4,6,8,20};
    int n=5;
    int arr[10];
    cout<<median(arr1,arr2,5,arr)<<endl;;
}
