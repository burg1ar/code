#include<iostream>
using namespace std;
void swap(int *x,int *y){
    int t=*x;
    *x=*y;
    *y=t;
}
void selection_sort_1(int arr[],int n){
    int i,j,min; //min is the index of the minimum element
    for(i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]) min=j;
        }
        if(min!=i) swap(arr[i],arr[min]);
    }
}
void selection_sort_2(int arr[],int n){
    int i,j,k,min;
    for(i=0;i<n-1;i++){ //i stops at (n-2)
        //cause the remaining element must be the biggest one
        min=arr[i];
        for(j=i+1;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                k=j;
            }
        }
        arr[k]=arr[i]; //if i stops at (n-1),executing this sentence will
        //modify the previous arr[k]
        arr[i]=min;
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={4,1,2,3,5};
    selection_sort_1(arr,5);
    display(arr,5);
    return 0;
}
