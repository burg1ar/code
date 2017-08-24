#include<iostream>
using namespace std;
#define MAXSIZE 50
int aux[MAXSIZE]; //auxiliary array
void merge(int arr[],int low,int mid,int high){
    //merge the sorted sequence arr[low...mid] and arr[mid+1...high]
    for(int i=low;i<=high;i++){
        aux[i]=arr[i];
    }//copy arr to aux
    int i,j,k;
    for(i=low,j=mid+1,k=i;i<=mid && j<=high;k++){
        if(aux[i]<aux[j]){
            arr[k]=aux[i++];
        }else{
            arr[k]=aux[j++];
        }
    }
    while(i<=mid) arr[k++]=aux[i++]; //if aux[low...mid] has remaining elements
    while(j<=high) arr[k++]=aux[j++]; //if aux[mid+1...high] has remaining elements
}
void merge_sort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={9,1,8,2,6,7,4,5,3};
    cout<<"before: ";
    display(arr,9);
    merge_sort(arr,0,8);
    cout<<"after: ";
    display(arr,9);
    return 0;
}
