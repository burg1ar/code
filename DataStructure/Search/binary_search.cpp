#include<iostream>
using namespace std;
int binary_search(int arr[],int n,int key){
    int low=0,high=n-1,mid;
    while(low<=high){ //"<=" can't be just "<" !!!
        mid=(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]<key){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1; //search failed
}
int main(){
    int arr[]={1,2,3,4,5};
    cout<<binary_search(arr,5,-1)<<endl;
    cout<<binary_search(arr,5,1)<<endl;
    cout<<binary_search(arr,5,2)<<endl;
    cout<<binary_search(arr,5,3)<<endl;
    cout<<binary_search(arr,5,4)<<endl;
    cout<<binary_search(arr,5,5)<<endl;
    cout<<binary_search(arr,5,6)<<endl;
    return 0;
}
