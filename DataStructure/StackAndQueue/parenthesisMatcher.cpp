#include<iostream>
#include<string>
#include<stack>
using namespace std;
//assume that str only contains '(' or ')' and is not empty
bool parenthesisMatcher(string str){
    stack<char> stk;
    for(auto it=str.begin();it!=str.end();++it){
        if(*it=='('){
            stk.push(*it);
        }else if(!stk.empty() && stk.top()=='('){
            stk.pop();
        }else{
            return false;
        }
    }
    return stk.empty()?true:false;
}
int main(){
    string str1="(()))";
    cout<<"(())) "<<parenthesisMatcher(str1)<<endl;
    string str2="((())";
    cout<<"((()) "<<parenthesisMatcher(str2)<<endl;
    string str3="((()))";
    cout<<"((())) "<<parenthesisMatcher(str3)<<endl;
    return 0;
}
