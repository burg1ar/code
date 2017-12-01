#include<iostream>
using namespace std;
int biSearchRecur(int key,int arr[],int low,int high){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(arr[mid]==key)
        return mid;
    else if(arr[mid]>key)
        return biSearchRecur(key,arr,low,mid-1);
    else
        return biSearchRecur(key,arr,mid+1,high);

}
int main(){
    int arr[]={1,2,3,4,5,6,7};
    int key;
    cout<<"search in :"<<endl;
    for(int i=0;i<7;++i) cout<<arr[i]<<" ";
    cout<<endl;
    while(cin>>key){
        cout<<"index of "<<key<<" : "<<biSearchRecur(key,arr,0,6)<<endl;
    }
    return 0;

}

