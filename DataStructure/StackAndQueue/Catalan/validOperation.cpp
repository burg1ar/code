/*given a sequence of stack operations(push or pop)
**let "1" represent "push","0" represent "pop"
**such as "1010" means "push pop push pop"
**judge the sequence is a valid operation sequence
*/
#include<iostream>
#include<vector>
using namespace std;
bool validOperation(vector<int> v){
    int i=0;
    int j=0,k=0; //j:count of 1,k:count of 0
    while(i<v.size()){
        if(v[i]==1)
            ++j;
        else
            ++k;
        if(k>j) return false;
        ++i;
    }
    if(j!=k) return false;
    else return true;
}
int main(){
    vector<int> v1={1,0,1,1,0,1,0,0};
    vector<int> v2={1,0,0,1,0,1,1,0};
    cout<<validOperation(v1)<<endl;
    cout<<validOperation(v2)<<endl;
    return 0;
}
