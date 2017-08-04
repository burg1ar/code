#include<iostream>
#include<stack>
#include<ctime>
using namespace std;
long factorial_recursive(int n){
    if(n==0 || n==1){
        return 1;
    }else{
        return n*factorial_recursive(n-1);
    }
}
long factorial_iterative(int n){
    if(n==0) return 1;
    long r=1;
    while(n>0){
        r*=n;
        --n;
    }
    return r;
}
//simulate the recursive process using stack
long factorial_stack(int n){
    stack<long> stk;
    if(n==0) return 1;
    for(int i=n;i>1;--i){
        stk.push(i); //'i' represents f(i) which is unknown
    }
    stk.push(1); //push f(1) which equals 1
    long r=1;
    while(!stk.empty()){
        r*=stk.top();
        stk.pop();
    }
    return r;
}
int main(){
    int n;
    while(cin>>n){
        cout<<"factorial_recursive("<<n<<") :"<<factorial_recursive(n)<<endl;
        cout<<"time consume: "<<(double)clock()/CLOCKS_PER_SEC<<endl;
        cout<<"factorial_iterative("<<n<<") :"<<factorial_iterative(n)<<endl;
        cout<<"time consume: "<<(double)clock()/CLOCKS_PER_SEC<<endl;
        cout<<"factorial_stack("<<n<<") :"<<factorial_stack(n)<<endl;
        cout<<"time consume: "<<(double)clock()/CLOCKS_PER_SEC<<endl;
    }
    return 0;
}
