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
long fibonacci_iterative(int n){
    long r=1,pre_r=1,pre_pre_r=1;
    while(n>2){
        r=pre_r+pre_pre_r;
        pre_pre_r=pre_r;
        pre_r=r;
        --n;
    }
    return r;
}
long fibonacci_stack(int n){
    stack<long> stk;
    long pre_r=1,pre_pre_r=1;
    for(int i=n;i>2;--i){
        stk.push(i); //'i' represent f(i) which is unknown
    }
    while(!stk.empty()){
        stk.top()=pre_r+pre_pre_r;
        pre_pre_r=pre_r;
        pre_r=stk.top();
        stk.pop();
    }
    return pre_r;
}
int main(){
    int n;
    while(cin>>n){
        cout<<"fibonacci_recursive("<<n<<"): "<<fibonacci_recursive(n)<<endl;
        cout<<"fibonacci_iterative("<<n<<"): "<<fibonacci_iterative(n)<<endl;
        cout<<"fibonacci_stack("<<n<<"): "<<fibonacci_stack(n)<<endl;
    }
    return 0;
}
