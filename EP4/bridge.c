#include "bridge.h"
#include <stdio.h>

#define maxV 1000

static int cnt, br, low[maxV], pre[maxV];
static vertex pa[maxV], b[maxV];

static void dfsB(Graph G, vertex v) {
    link p;
    low[v] = pre[v] = cnt++;
    for (p = G->adj[v]; p!= NULL; p = p->next) {
        if (pre[p->w] == -1) {
            pa[p->w] = v;
            dfsB(G, p->w);
            if (low[p->w] < low[v])
                low[v] = low[p->w];
        }
        else if (pre[p->w] < low[v] && pa[v] != p->w)
            low[v] = pre[p->w];
    }
    if (pre[v] == low[v] && pa[v] != v) {
        b[v] = pa[v];
        br++;
    }
}

void UGRAPHbridges(Graph G) {
    vertex v;
    for (v = 0; v < G->V; v++)
        pre[v] = b[v] = pa[v] = -1;
    cnt = br = 0;
    for (v = 0; v < G->V; v++) {
        if (pre[v] == -1) {
            pa[v] = v;
            dfsB(G, v);
        }
    }
    printf("%d\n", br);
    for (v = 0; v < G->V; v++)
        if (b[v] != -1)
            printf("%d %d\n", b[v], v);
}

