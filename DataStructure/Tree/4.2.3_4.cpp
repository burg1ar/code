/* common ancestor of i and j */
#include<iostream>
using namespace std;
int comm_ancestor(char tr[],int i,int j){
    //index of tree[] start from 1,"#" represents empty cell
    if(tr[i]!='#' && tr[j]!='#'){
        while(i!=j){
            if(i>j)
                i=i/2;
            else
                j=j/2;
        }
        return i;
    }
}
int comm_ancestor_r(char tr[],int i,int j){
    if(tr[i]!='#' && tr[j]!='#'){
        if(i>j){
            return comm_ancestor_r(tr,i/2,j);
        }
        else if(i<j){
            return comm_ancestor_r(tr,i,j/2);
        }
        else{
            return i;
        }
    }
}
int main(){
    char tr[]={'#','a','b','c','d','e','#','#','#','#','f'};
    cout<<"comm_ancestor of 3 and 10 is "<<comm_ancestor(tr,3,10)<<endl;
    cout<<"comm_ancestor_r of 3 and 10 is "<<comm_ancestor_r(tr,3,10)<<endl;
    return 0;
}
