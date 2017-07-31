#include<iostream>
#include<string>
#include<sstream>
#include<stack>
using namespace std;
bool isDigit(char ch){
    return ch>='0' && ch<='9';
}
bool isOperator(char ch){
    return ch=='+' || ch=='-' || ch=='*' ||ch=='/';
}
int priority(char ch){
    switch(ch){
        case '+':case '-':
            return 1;
        case '*':case '/':
            return 2;
    }
}
//shunting-yard algorithm
string infix_to_postfix(string expr){
    stack<char> stk;
    string output="";
    for(auto it=expr.begin();it!=expr.end();++it){
        if(isDigit(*it)){
            output.push_back(*it);
        }else if(isOperator(*it)){
            while(!stk.empty() && isOperator(stk.top())
                    && priority(*it)<=priority(stk.top())){
                output.push_back(stk.top());
                stk.pop();
            }
            stk.push(*it);
        }else if(*it=='('){
            stk.push(*it);
        }else if(*it==')'){
            while(!stk.empty() && stk.top()!='('){
                output.push_back(stk.top());
                stk.pop();
            }
            if(stk.empty()){
                return "parenthesis dismatch";
            }else{
                //the top of stack is a '('
                stk.pop();
            }
        }else{
            //convert char to string,head file:sstream
            stringstream stream;
            stream<<*it;
            return "invalid notation: "+stream.str();
        }
    }
    while(!stk.empty()){
        if(stk.top()=='('){
            return "parenthesis dismatch";
        }
        output.push_back(stk.top());
        stk.pop();
    }
    return output;
}
int main(){
    string expr;
    while(cin>>expr){
        cout<<"infix notation: "<<expr<<endl;
        cout<<"postfix notation: "<<infix_to_postfix(expr)<<endl;
    }
    return 0;
}
