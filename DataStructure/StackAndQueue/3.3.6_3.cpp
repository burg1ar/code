#include<iostream>
#include<stack>
#include<ctime>
using namespace std;
double p(int n,double x){
    typedef struct{
        int no;
        double val;
    }Elem;
    stack<Elem> stk;
    Elem elem;
    double p0=1,p1=2*x;
    for(int i=n;i>=2;--i){
        elem={i,0};
        stk.push(elem);
    }
    while(!stk.empty()){
        stk.top().val=2*x*p1-2*(stk.top().no-1)*p0;
        p0=p1;
        p1=stk.top().val;
        stk.pop();
    }
    if(n==0){
        return p0;
    }
    return p1;
}
double p_recursive(int n,double x){
    if(n==0){
        return 1;
    }else if(n==1){
        return 2*x;
    }else{
        return 2*x*p_recursive(n-1,x)-2*(n-1)*p_recursive(n-2,x);
    }
}
int main(){
    int n;
    double x;
    while(cin>>n>>x){
        cout<<"non-recursive: "<<p(n,x)<<endl;
        cout<<"time consume: "<<(double)clock()/CLOCKS_PER_SEC<<endl;
        cout<<"recursive: "<<p_recursive(n,x)<<endl;
        cout<<"time consume: "<<(double)clock()/CLOCKS_PER_SEC<<endl;
    }
    return 0;
}
