//find k_th element,count from 1
#include<iostream>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    while(low<high){
        while(low<high && arr[high]>=pivot) high--;
        arr[low]=arr[high];
        while(low<high && arr[low]<=pivot) low++;
        arr[high]=arr[low];
    }
    arr[low]=pivot;
    return low;
}
int k_th(int arr[],int low,int high,int k){
    int pivotpos=partition(arr,low,high);
    if(pivotpos==k-1){ //count from 1
        return arr[pivotpos];
    }else if(pivotpos<k-1){
        k_th(arr,pivotpos+1,high,k);
    }else{
        k_th(arr,low,pivotpos-1,k);
    }
}
int main(){
    int arr[]={4,5,1,2,8,7,9,3,6};
    int k;
    cin>>k;
    cout<<k_th(arr,0,8,k)<<endl;
    return 0;
}
