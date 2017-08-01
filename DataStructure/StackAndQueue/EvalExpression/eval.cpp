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
//update:detect missin/redundant operator,add "digCount" and "opCount"
string infix_to_postfix(string expr){
    stack<char> stk;
    int digCount=0,opCount=0;
    string output="";
    for(auto it=expr.begin();it!=expr.end();++it){
        if(isDigit(*it)){
            output.push_back(*it);
            ++digCount;
        }else if(isOperator(*it)){
            while(!stk.empty() && isOperator(stk.top())
                    && priority(*it)<=priority(stk.top())){
                output.push_back(stk.top());
                ++opCount;
                stk.pop();
            }
            stk.push(*it);
        }else if(*it=='('){
            stk.push(*it);
        }else if(*it==')'){
            while(!stk.empty() && stk.top()!='('){
                output.push_back(stk.top());
                ++opCount;
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
        ++opCount;
        stk.pop();
    }
    if(digCount-opCount>1){
        return "missing operator";
    }else if(digCount-opCount<1){
        return "redundant operator";
    }else{
        return output;
    }
}
double eval(string expr){
    stack<double> stk;
    double x,y,z;
    for(auto it=expr.begin();it!=expr.end();++it){
        if(isDigit(*it)){
            stk.push(*it-'0');
        }else if(isOperator(*it)){
            x=stk.top();stk.pop();
            y=stk.top();stk.pop();
            switch(*it){
                case '+':
                    z=y+x;break;
                case '-':
                    z=y-x;break;
                case '*':
                    z=y*x;break;
                case '/':
                    z=y/x;break;
            }
            stk.push(z);
        }else{
            cout<<expr<<endl;
            return 0; //ERROR
        }
    }
    return stk.top();
}
int main(){
    string expr,temp;
    while(cin>>expr){
        cout<<"infix notation: "<<expr<<endl;
        temp=infix_to_postfix(expr);
        cout<<"postfix notation: "<<temp<<endl;
        cout<<eval(temp)<<endl;
    }
    return 0;
}
