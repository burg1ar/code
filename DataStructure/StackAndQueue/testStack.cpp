#include<iostream>
#include"stack.h"
using namespace std;
int main(){
    SqStack stack;
    init(stack);
    cout<<stack.top<<endl;
//    cout<<stack.data[5]<<endl;
    push(stack,8);
    int x;
    getTop(stack,x);
    cout<<x<<endl;
    cout<<isEmpty(stack)<<endl;
    return 0;
}
