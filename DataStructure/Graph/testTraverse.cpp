#include"implementation.h"
int main(){
    MGraph G;
    createGraph(G);
    cout<<"BFS:"<<endl;
    BFSTraverse(G);
    cout<<endl;
    cout<<"DFS:"<<endl;
    DFSTraverse(G);
    cout<<endl;
    return 0;
}
