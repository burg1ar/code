#include<iostream>
#include<climits>
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
using namespace std;
typedef char VertexType;
typedef int EdgeType;
typedef enum{DG,DN,UDG,UDN} GraphKind;
typedef struct{
    VertexType Vex[MAX_VERTEX_NUM];
    EdgeType Edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vernum,arcnum;
    GraphKind kind;
}MGraph,Graph;
int locate(MGraph G,VertexType u){
    for(int i=0;i<G.vernum;++i){
        if(G.Vex[i]==u)
            return i;
    }
    return -1;
}
bool createDG(MGraph &G){
    return true;
}
bool createDN(MGraph &G){
    cout<<"input G.vernum and G.arcnum :"<<endl;
    cin>>G.vernum>>G.arcnum;
    cout<<"input the vertex :"<<endl;
    for(int i=0;i<G.vernum;++i)
        cin>>G.Vex[i];
    //initialize the matrix
    for(int i=0;i<G.vernum;++i){
        for(int j=0;j<G.vernum;++j){
        	if(i==j)
        		G.Edge[i][j]=0;
        	else
        		G.Edge[i][j]=INFINITY;
        }
    }
    cout<<"input all the arcs connected by two vertexes and their corresponding weights"<<endl;
    cout<<"Example:a b 9,means 'a->b with the weight of 9'"<<endl;
    int i,j,weight;
    VertexType v1,v2;
    for(int k=0;k<G.arcnum;++k){
        cin>>v1>>v2>>weight;
        i=locate(G,v1);j=locate(G,v2);
        G.Edge[i][j]=weight;
    }
    return true;
}
bool createUDG(MGraph &G){
    cout<<"input G.vernum and G.arcnum :"<<endl;
    cin>>G.vernum>>G.arcnum;
    cout<<"input the vertex :"<<endl;
    for(int i=0;i<G.vernum;++i)
        cin>>G.Vex[i];
    //initialize the matrix
    for(int i=0;i<G.vernum;++i)
        for(int j=0;j<G.vernum;++j)
            G.Edge[i][j]=0;
    cout<<"input all the arcs connected by two vertexes"<<endl;
    cout<<"Example:a b"<<endl;
    int i,j;
    VertexType v1,v2;
    for(int k=0;k<G.arcnum;++k){
        cin>>v1>>v2;
        i=locate(G,v1);j=locate(G,v2);
        G.Edge[i][j]=1;
        G.Edge[j][i]=1; //the matrix is symmetric
    }
    return true;
}
bool createUDN(MGraph &G){
    return true;
}
bool createGraph(MGraph &G){
    cout<<"input graph kind number DG(0),DN(1),UDG(2),UDN(3)"<<endl;
    int t;
    cin>>t;
    G.kind=(GraphKind)t;
    switch(G.kind){
        case DG:return createDG(G);
        case DN:return createDN(G);
        case UDG:return createUDG(G);
        case UDN:return createUDN(G);
        default:return false;
    }
}
int firstAdjVex(Graph G,int v){
    for(int i=0;i<G.vernum;++i){
        if(G.Edge[v][i]!=0 && G.Edge[v][i]!=INFINITY)
            return i;
    }
    return -1;
}
int nextAdjVex(Graph G,int v,int w){
    for(int i=w+1;i<G.vernum;++i){
        if(G.Edge[v][i]!=0 && G.Edge[v][i]!=INFINITY)
            return i;
    }
    return -1;
}
void printMatrix(Graph g){
	int count;
	for(int i=0;i<g.vernum;++i){
		count=0;
		for(int j=0;j<g.vernum;++j){
			if(g.Edge[i][j]==INFINITY)
				cout<<"INF"<<" ";
			else
				cout<<g.Edge[i][j]<<"   ";
			count++;
		}
		if(count==g.vernum) cout<<endl;
	}
}
bool visited[MAX_VERTEX_NUM];
void DFS(Graph G,int v){
    cout<<G.Vex[v]<<" "; //visit vertex "v"
    visited[v]=true;
    for(int w=firstAdjVex(G,v);w>=0;w=nextAdjVex(G,v,w)){
        if(!visited[w]) DFS(G,w);
    }
}
void DFSTraverse(Graph G){
    for(int v=0;v<G.vernum;++v){
        visited[v]=false;
    }
    for(int v=0;v<G.vernum;++v){
        if(!visited[v]) DFS(G,v);
    }
}
