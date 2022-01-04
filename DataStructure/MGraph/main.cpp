#include "MGraph.h"

int main()
{
    MGraph G;
    CreateUDN(G);

    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            if (G.arcs[i][j].adj < INFINITY) {
                printf("%d\t", G.arcs[i][j].adj);
            } else {
                printf("inf\t");
            }
        }
        printf("\n");
    }
    printf("\n");

    DFSTraverse(G, PrintVex);  
    printf("\n");

    BFSTraverse(G, PrintVex);
    printf("\n");

    return 0;
}