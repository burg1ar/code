/*A[0...n] is an array whose elements are distinct from each other
 */
#include<iostream>
using namespace std;
void count_sort(int A[],int B[],int n){
    int count;
    for(int i=0;i<n;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(A[j]<A[i]) count++;
        }
        B[count]=A[i];
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int A[]={9,3,4,6,5,2,1,7,8,0};
    int *B=new int[10];
    cout<<"before: ";
    display(A,10);
    count_sort(A,B,10);
    cout<<" after: ";
    display(B,10);
    return 0;
}
