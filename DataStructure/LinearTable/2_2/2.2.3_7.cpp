/*
将两个有序表合并为一个有序表，时间复杂度为O(max(m,n))
*/
#include<iostream>
using namespace std;
void combine(int arr1[],int arr2[],int n1,int n2,int arr3[]){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
        }else{
            arr3[k++]=arr2[j++];
        }
    }
    while(i<n1){
        arr3[k++]=arr1[i++];
    }while(j<n2){
        arr3[k++]=arr2[j++];
    }
}
int main(){
    int arr1[]={1,3,5,7,9};
    int arr2[]={2,4,6,8,10,12,15,17};
    int arr3[13];
    combine(arr1,arr2,5,8,arr3);
    for(int i=0;i<13;i++){
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
    return 0;
}
