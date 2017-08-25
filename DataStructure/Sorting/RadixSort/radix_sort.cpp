#include<iostream>
#include<queue>
using namespace std;
int maxDigitNum(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(max<arr[i])
            max=arr[i];
    }
    int num=1;
    while(max>=10){
        max/=10;
        num++;
    }
    return num;
}
void radix_sort(int arr[],int n){
    queue<int> bucket[10];
    int d=maxDigitNum(arr,n);
    int radix=1;
    for(int i=0;i<d;i++){
        for(int j=0;j<n;j++){
            bucket[(arr[j]/radix)%10].push(arr[j]);
        }
        for(int k=0,p=0;k<10;k++){
            while(!bucket[k].empty()){
                arr[p++]=bucket[k].front();
                bucket[k].pop();
            }
        }
        radix*=10;
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={278,109,63,930,589,184,505,269,8,83};
    cout<<"before: ";
    display(arr,10);
    radix_sort(arr,10);
    cout<<" after: ";
    display(arr,10);
    return 0;
}
