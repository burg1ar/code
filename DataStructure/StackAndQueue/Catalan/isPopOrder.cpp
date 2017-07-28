#include<iostream>
#include<stack>
#include<vector>
using namespace std;
bool isPopOrder(vector<int> input,vector<int> output){
    if(input.empty() || output.empty() ||input.size()!=output.size())
        return false;
    stack<int> stk;
    auto oit=output.begin();
    for(auto it=input.begin();it!=input.end();++it){
        stk.push(*it);
        while(!stk.empty() && stk.top()==(*oit)){
            stk.pop();
            ++oit;
        }
    }
    return stk.empty()?true:false;
}
int main(){
    vector<int> input={1,2,3,4};
    vector<int> output1={1,2,3,4};
    vector<int> output2={1,4,2,3};
    vector<int> output3={2,4,1,3};
    vector<int> output4={1,3,2,4};
    vector<int> output5={4,3,1,2};
    cout<<isPopOrder(input,output1)<<endl;
    cout<<isPopOrder(input,output2)<<endl;
    cout<<isPopOrder(input,output3)<<endl;
    cout<<isPopOrder(input,output4)<<endl;
    cout<<isPopOrder(input,output5)<<endl;
    vector<int> ip={1,2,3,4,5};
    vector<int> op1={2,3,1,5,4};
    vector<int> op2={4,2,1,3,5};
    cout<<isPopOrder(ip,op1)<<endl;
    cout<<isPopOrder(ip,op2)<<endl;
    return 0;
}
