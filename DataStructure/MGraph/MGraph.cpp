#include "MGraph.h"

bool visited[MAX_VERTEX_NUM] = { false };

#define INFO_LENGTH 100
void InputInfo(char*& info)
{
    int len;
    char str[INFO_LENGTH];
    scanf("%s", str);
    len = strlen(str);

    info = (char*)malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        info[i] = str[i];
    }
    info[len] = '\0';
}

Status CreateUDN(MGraph& G)
{
    int IncInfo = 0;
    scanf("%d%d%d", &G.vexnum, &G.arcnum, &IncInfo);

    for (int i = 0; i < G.vexnum; i++) {
        scanf("%s", G.vexs[i]);
    }

    // 邻接矩阵的初始化在定义ArcCell时已经完成
    for (int k = 0; k < G.arcnum; k++) {
        int w;
        VertexType u;
        VertexType v;
        scanf("%s%s%d", u, v, &w);
        int i = LocateVex(G, u);
        int j = LocateVex(G, v);
        G.arcs[i][j].adj = w;
        if (IncInfo) {
            InputInfo(G.arcs[i][j].info);
        }
        G.arcs[j][i] = G.arcs[i][j];
    }
    return OK;
}

int LocateVex(MGraph G, VertexType u)
{
    for (int i = 0; i < G.vexnum; i++) {
        if (strcmp(u, G.vexs[i]) == 0) {
            return i;
        }
    }
    return -1;
}

Status GetVex(MGraph G, int v, VertexType& value)
{
    if (v < 0 || v >= G.vexnum) {
        return ERROR;
    }

    strcpy(value, G.vexs[v]);
    return OK;
}

Status PutVex(MGraph& G, int v, VertexType value)
{
    if (v < 0 || v >= G.vexnum) {
        return ERROR;
    }

    strcpy(G.vexs[v], value);
    return OK;
}

int FirstAdjVex(MGraph G, int v)
{
    // 确保v合法
    if (v >= 0 && v < G.vexnum) {
        for (int j = 0; j < G.vexnum; j++) {
            if (G.arcs[v][j].adj != INFINITY) {
                return j;
            }
        }
    }
    return -1;
}

int NextAdjVex(MGraph G, int v, int w)
{
    // 确保v,w合法
    if (v >= 0 && v < G.vexnum && w >= 0 && w < G.vexnum) {
        for (int j = w + 1; j < G.vexnum; j++) {
            if (G.arcs[v][j].adj != INFINITY) {
                return j;
            }
        }
    }
    return -1;
}

Status (*VisitFunc)(VertexType& v);

void DFSTraverse(MGraph G, Status (*visit)(VertexType& v))
{
    VisitFunc = visit;
    memset(visited, 0, sizeof(visited)); //全部初始化未被访问

    for (int v = 0; v < G.vexnum; v++) {
        if (!visited[v]) {
            // 划分成几个连通分量分别dfs
            DFS(G, v);
        }
    }
}

void DFS(MGraph G, int v)
{
    VisitFunc(G.vexs[v]);
    visited[v] = true;
    for (int w = FirstAdjVex(G, v); w != -1; w = NextAdjVex(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}

void BFSTraverse(MGraph G, Status (*visit)(VertexType& v))
{
    // 全部初始化未被访问
    memset(visited, 0, sizeof(visited));

    SqQueue q;
    InitQueue(q);

    /** 
     * PPT里的代码是, 先访问再进队列, 遍历顺序与进队列顺序一致
     * 这里是队列存储待访问点序列，出队列后访问，遍历顺序与出队列顺序一致
     * 由于队列先进先出, 所以两种实现得到的遍历顺序一致
     * */
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            // 划分成几个连通分量分别bfs
            EnQueue(q, i);
            while (!QueueEmpty(q)) {
                // 访问
                int u;
                DeQueue(q, u);
                if (!visited[u]) {
                    visit(G.vexs[u]);
                    visited[u] = true;
                }
                // 访问了u要立刻将u的邻接点存入队列
                for (int v = FirstAdjVex(G, u); v != -1; v = NextAdjVex(G, u, v)) {
                    if (!visited[v]) {
                        EnQueue(q, v);
                    }
                }
            }
        }
    }
    DestroyQueue(q);
}

Status PrintVex(VertexType& v)
{
    printf("%s\t", v);
    return OK;
}

// Status InsertVex(MGraph& G, VertexType v);
// Status DeleteVex(MGraph& G, int v);
// Status InsertArc(MGraph& G, int v, int w, VRType weight, InfoType* info);
// Status DeleteArc(MGraph& G, int v, int w);