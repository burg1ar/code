#include"implementation.h"
int main(){
    MGraph G;
    createGraph(G);
    DFSTraverse(G);
    cout<<endl;
    return 0;
}
