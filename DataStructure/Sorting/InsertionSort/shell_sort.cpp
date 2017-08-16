#include<iostream>
using namespace std;
void shell_sort(int arr[],int n){
    int gap,key;
    int i,j;
    for(gap=n/2;gap>=1;gap/=2){
        for(i=gap;i<n;i++){
            key=arr[i];
            for(j=i-gap;j>=0 && arr[j]>key;j-=gap){
                arr[j+gap]=arr[j];
            }
            arr[j+gap]=key;
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
    int arr[]={9,10,2,5,4,3,6,1,7,8};
    shell_sort(arr,10);
    display(arr,10);
    return 0;
}
