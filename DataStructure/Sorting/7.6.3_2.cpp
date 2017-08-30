/* assuming an array A[0...m+n-1] that has two sorted(ascending order)
 * subsequences A[0...m-1] and A[m...m+n-1]
 *sort A (ascending order)
 */
#include<iostream>
using namespace std;
void merge(int A[],int m,int n){
    int B[m+n];
    for(int i=0;i<m+n;i++){
        B[i]=A[i];
    }//copy A to B
    int i=0,j=m,k=0;
    while(i<m && j<m+n){
        if(B[i]<B[j])
            A[k++]=B[i++];
        else
            A[k++]=B[j++];
    }
    while(i<m) A[k++]=B[i++];
    while(j<m+n) A[k++]=B[j++];
}//T(N)=O(N),S(N)=O(N)
int main(){
    int A[]={1,3,5,7,9,11,12,2,4,6,8,10};
    cout<<"before : ";
    for(auto i:A){
        cout<<i<<" ";
    }
    cout<<endl;
    merge(A,7,5);
    cout<<" after : ";
    for(auto i:A){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
