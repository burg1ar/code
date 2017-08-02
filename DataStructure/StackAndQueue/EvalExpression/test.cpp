#include<iostream>
#include"expressionTree.h"
using namespace std;
int main(){
    string expr,temp;
    TNode* tr;
    while(cin>>expr){
        cout<<"infix notation: "<<expr<<endl;
        temp=infix_to_postfix(expr);
        cout<<"postfix notation: "<<temp<<endl;
        tr=expressionTree(temp);
        printTree(tr);
        cout<<endl;
        cout<<"result: "<<eval(temp)<<endl;
    }
    string postfix="";
    getPostfix(tr,postfix);
    cout<<"get postfix from expression tree: "<<postfix<<endl;
    cout<<"postfix to infix: "<<postfix_to_infix(postfix)<<endl;
    cout<<"evalInfix: "<<evalInfix(expr)<<endl;
    return 0;
}
