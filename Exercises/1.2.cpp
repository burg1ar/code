#include<iostream>
using namespace std;
#define MAX 20
typedef int ElemType;
//the size of arr is big enough
void func(ElemType arr[],int n,ElemType x){
    int low=1,high=n;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(x==arr[mid]){
            if(mid==n-1)
                return;
            else
                swap(arr[mid],arr[mid+1]);
            return;
        }else if(x>arr[mid]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    for(int i=n;i>low;--i){
        arr[i]=arr[i-1];
    }
    arr[low]=x;
}
void print(ElemType arr[],int n){
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    ElemType arr[MAX];
    for(int i=0;i<7;++i)
        arr[i]=3*i-2;
    print(arr,7);
    func(arr,7,6);
    print(arr,8);
    func(arr,8,6);
    print(arr,8);
    func(arr,8,16);
    print(arr,8);
    return 0;
}
