#include<climits>
#define INTINITY INT_MAX
#define MAX_VERTEX_NUM 20
typedef char VertexType;
typedef int EdgeType;
typedef enum{DG,DN,UDG,UDN} GraphKind;
struct MGraph;
bool createGraph(MGraph &G);
bool destroyGraph(MGraph &G);
int locate(MGraph G,VertexType v);
int firstAdjVex(MGraph G,int v);
int nextAdjVex(MGraph G,int v,int w);
void BFS(MGraph G);
void DFS(MGraph G);
