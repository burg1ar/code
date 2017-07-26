#include<iostream>
using namespace std;
int findKey(int arr[],int n){
    int count[n];
    for(int k=0;k<n;k++){
        count[k]=0;
    }
    int i=0;
    while(i<n){
        count[arr[i]]++;
        i++;
    }
    int key=-1;
    int j=0;
    while(j<n){
        if(count[j]>n/2){
            key=j;
        }
        j++;
    }
    return key;
}
int main(){
    int arr[]={0,5,5,3,5,7,5,5};
    cout<<findKey(arr,8)<<endl;
    int arr2[]={0,5,5,3,5,2,5,7};
    cout<<findKey(arr2,8)<<endl;
    return 0;

}
