#include<iostream>
using namespace std;
void bubble_sort_up(int arr[],int n){
    int i,j,temp;
    int flag;
    for(i=0;i<n;i++){
        flag=0;
        for(j=n-1;j>i;j--){
            if(arr[j-1]>arr[j]){
                //swap arr[j-1] and arr[j]
                temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
                flag=1;
            }
        }
        if(flag==0) return;
    }
}
void bubble_sort_down(int arr[],int n){
    int i,j,temp;
    int flag;
    for(int i=n-1;i>0;i--){
        flag=0;
        for(j=0;j<i;j++){
            if(arr[j+1]<arr[j]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                flag=1;
            }
        }
        if(flag==0) return;
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={5,4,2,1,3};
    bubble_sort_up(arr,5);
    display(arr,5);
    int arr1[]={5,4,2,1,3};
    bubble_sort_down(arr1,5);
    display(arr1,5);
    return 0;
}
