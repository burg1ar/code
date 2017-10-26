#include"implementation.h"
int add(int x,int y){
    if(x==INFINITY || y==INFINITY)
        return INFINITY;
    else
        return x+y;
}//in case of OVERFLOW,cause the calculation involves INFINITY which is equal to "INT_MAX"
void dijkstra(Graph g,int v,int dist[],int path[]){
    bool set[g.vernum];
    int min,i,j,u;
    for(i=0;i<g.vernum;++i){
        dist[i]=g.Edge[v][i];
        set[i]=false;
        if(g.Edge[v][i]<INFINITY)
            path[i]=v;
        else
            path[i]=-1;
    }//initialize
    set[v]=true;path[v]=-1;
    for(i=0;i<g.vernum;++i){
        min=INFINITY;
        for(j=0;j<g.vernum;++j){
            if(set[j]==false && dist[j]<min){
                u=j;
                min=dist[j];
            }
        }
        set[u]=true;
        for(j=0;j<g.vernum;++j){
            if(set[j]==false && add(dist[u],g.Edge[u][j])<dist[j]){
                dist[j]=dist[u]+g.Edge[u][j];
                path[j]=u;
            }
        }
    }
}
void printPath(Graph g,int path[],int v){
    int stk[g.vernum],top=-1;
    while(path[v]!=-1){
        stk[++top]=v;
        v=path[v];
    }
    stk[++top]=v;
    while(top!=-1){
        cout<<g.Vex[stk[top--]]<<" ";
    }
    cout<<endl;
}
int main(){
    Graph g;
    createGraph(g);
    int dist[MAX_VERTEX_NUM],path[MAX_VERTEX_NUM];
    dijkstra(g,0,dist,path);
    int v;
    while(cin>>v){
        printPath(g,path,v);
    }
    cout<<"path[]:"<<endl;
    for(int i=0;i<g.vernum;++i){
        cout<<path[i]<<" ";
    }
    cout<<endl;
//    printMatrix(g);
    return 0;
}
