#include<iostream>
using namespace std;
void max_heapify(int arr[],int start,int end){
    int parent=start;
    int child=2*start+1; //left child
    while(child<end){
        //compare left child and right child first,choose the bigger one
        if(child+1<end && arr[child]<arr[child+1]) child++;
        //compare child and parent
        if(arr[parent]>arr[child]){
            return;
        }else{
            swap(arr[parent],arr[child]);
            parent=child; //continue adjusting down
            child=2*parent+1;
        }
    }
}
void build_max_heap(int arr[],int n){
    //start from the position of (n/2-1)
    for(int i=n/2-1;i>=0;i--){
        max_heapify(arr,i,n-1);
    }
}
void heap_sort(int arr[],int n){
    build_max_heap(arr,n);
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]); //output the root element(which is the max)
        //by swapping it for the bottom element
        max_heapify(arr,0,i-1); //max_heapify the remaining (i-1) elements
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={3,1,2,4,5,9,7,8,6};
    heap_sort(arr,9);
    display(arr,9);
    return 0;
}
