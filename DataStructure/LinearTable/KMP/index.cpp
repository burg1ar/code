#include<iostream>
#include<string>
using namespace std;
//简单模式匹配
int index(string s,string t){
    int m=s.size();
    int n=t.size();
    int i,j;
    for(i=0;i<m-n+1;++i){
        for(j=0;j<n;++j){
            if(t[j]!=s[j+i]) break;
        }
//        cout<<j<<endl;
        if(j==n) return i;
    }
    return -1;
}
int main(){
    string s="being";
    string t="ei";
    cout<<index(s,t)<<endl;
    return 0;
}
