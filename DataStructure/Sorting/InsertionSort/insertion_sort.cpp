#include<iostream>
using namespace std;
void insertion_sort(int arr[],int n){
    int i,j;
    int key;
    for(i=1;i<n;i++){
        key=arr[i];
        for(j=i-1;j>=0 && arr[j]>key;j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr1[]={1,3,2,5,4};
    int arr2[]={5,4,3,2,1};
    insertion_sort(arr1,5);
    display(arr1,5);
    insertion_sort(arr2,5);
    display(arr2,5);
    return 0;
}
