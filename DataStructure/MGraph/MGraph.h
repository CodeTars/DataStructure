#include "PreDefined.h"
#include "SqQueue.h"
#include <string.h>

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20

typedef int VRType;
typedef char InfoType;
typedef char VertexType[20];

typedef struct ArcCell {
    VRType adj = INFINITY; //无向网的边权初值为无穷
    InfoType* info = NULL; //初始化为无信息
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct MGraph {
    VertexType vexs[MAX_VERTEX_NUM]; // 顶点数组
    AdjMatrix arcs; // 无向带权边数组
    int vexnum = 0;
    int arcnum = 0;
} MGraph;

Status CreateUDN(MGraph& G);
int LocateVex(MGraph G, VertexType u);
Status GetVex(MGraph G, int v, VertexType& value);
Status PutVex(MGraph& G, int v, VertexType value);
int FirstAdjVex(MGraph G, int v);
int NextAdjVex(MGraph G, int v, int w);
void DFSTraverse(MGraph G, Status (*visit)(VertexType& v));
void DFS(MGraph G, int v);
void BFSTraverse(MGraph G, Status (*visit)(VertexType& v));
Status PrintVex(VertexType& v);

Status InsertVex(MGraph& G, VertexType v);
Status DeleteVex(MGraph& G, int v);
Status InsertArc(MGraph& G, int v, int w, VRType weight, InfoType* info);
Status DeleteArc(MGraph& G, int v, int w);
