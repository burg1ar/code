#include<iostream>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    while(low<high){
        while(low<high && arr[high]>=pivot) --high;
        //stop when finding the element that is less than pivot
        arr[low]=arr[high]; //move the element(at high position) to low position
        while(low<high && arr[low]<=pivot) ++low;
        //stop when finding the element that is bigger than pivot
        arr[high]=arr[low]; //move the element(at low position) to high position
    }
    arr[low]=pivot; //put pivot to its final position
    return low;
}
void qsort(int arr[],int low,int high){
    if(low<high){
        int pivotpos=partition(arr,low,high);
        qsort(arr,low,pivotpos-1);
        qsort(arr,pivotpos+1,high);
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={4,1,8,9,7,10,5,6,2,3};
    qsort(arr,0,9);
    display(arr,10);
    return 0;
}
