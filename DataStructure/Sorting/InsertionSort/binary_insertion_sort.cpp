#include<iostream>
using namespace std;
void binary_insertion_sort(int arr[],int n){
    int i,j,low,high,mid;
    int key;
    for(int i=1;i<n;i++){
        key=arr[i];
        low=0;high=i-1;
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]>key)
                high=mid-1;
            else
                low=mid+1;
        }//loop out when high<low
        for(j=i-1;j>high;j--){
            arr[j+1]=arr[j];
        }
        arr[high+1]=key;
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
    binary_insertion_sort(arr1,5);
    display(arr1,5);
    binary_insertion_sort(arr2,5);
    display(arr2,5);
    return 0;
}
