#include<iostream>
#include<string>
using namespace std;
int naive_matcher_v1(string text,string pattern){
    int n=text.size();
    int m=pattern.size();
    int s,i;
    for(s=0;s<n-m+1;++s){
        for(i=0;i<m;++i){
            if(text[s+i]!=pattern[i]) break;
        }
        if(i==m) return s;
    }
    return -1;
}
int naive_matcher_v2(string text,string pattern){
    int n=text.size();
    int m=pattern.size();
    int i=0,j=0;
    while(i<n && j<m){
        if(text[i]==pattern[j]){
            ++i;++j;
        }else{
            i=i-j+1;j=0;    //shift=i-j,increase shift by 1
        }
    }
    if(j==m) return i-j;
    else return -1;
}
int* prefix_function(string pattern){
    int n=pattern.size();
    int* next=new int[n];    //next[i]=0 for all i=0,1,...,n-1
    int i=1,j=0;
    while(i<n){
        if(pattern[i]==pattern[j]){
            next[i]=j+1;
            ++i;++j;
        }else{
            if(j>0){
                j=next[j-1];
            }else{
                next[i]=0;
                ++i;
            }
        }
    }
    return next;
}
int kmp(string text,string pattern){
    int* next=prefix_function(pattern);
    int i=0,j=0;
    while(i<text.size() && j<pattern.size()){
        if(text[i]==pattern[j]){
            ++i;++j;
        }else{
            if(j>0){
                j=next[j-1];
            }else{
                ++i;
            }
        }
    }
    if(j==pattern.size()){
        return i-j;
    }else{
        return -1;
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    string pattern="aaab";
    int n=pattern.size();
    int* next=new int[n];
    next=prefix_function(pattern);
    display(next,n);
    string text="acacbbcaaabaabccabacacdb";
    cout<<kmp(text,pattern)<<endl;
    cout<<naive_matcher_v1(text,pattern)<<endl;
    cout<<naive_matcher_v2(text,pattern)<<endl;
    return 0;
}
