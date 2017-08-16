//two-way bubble sort
#include<iostream>
using namespace std;
void swap(int *x,int *y){
    int t=*x;
    *x=*y;
    *y=t;
}
void two_way_bubble(int arr[],int n){
    int low=0,high=n-1;
    int flag; //swap happened:1
    int i,j;
    while(low<high){
        flag=0;
        for(i=low;i<high;i++){
            //bubble down from the start
            if(arr[i]>arr[i+1]){
                swap(arr+i,arr+i+1);
                flag=1;
            }
        }
        high--;
        for(j=high;j>low;j--){
            //bubble up from the end
            if(arr[j]<arr[j-1]){
                swap(arr+j,arr+j-1);
                flag=1;
            }
        }
        low++;
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
    int arr[]={1,4,5,3,2};
    two_way_bubble(arr,5);
    display(arr,5);
    return 0;
}
