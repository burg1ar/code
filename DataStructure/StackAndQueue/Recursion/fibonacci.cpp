#include<iostream>
#include<stack>
using namespace std;
long fibonacci_recursive(int n){
    if(n==1 || n==2){
        return 1;
    }else{
        return fibonacci_recursive(n-1)+fibonacci_recursive(n-2);
    }
}
int main(){
    int n;
    while(cin>>n){
        cout<<"fibonacci_recursive("<<n<<"): "<<fibonacci_recursive(n)<<endl;
    }
    return 0;
}
