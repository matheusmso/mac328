#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

static int **MATRIXinit(int l, int c, int val) {
    int i, j;
    int ** adj = malloc(l * sizeof(int *));
    for (i = 0; i < l; i++) {
        adj[i] = malloc(c * sizeof(int));
    }
    for (i = 0; i < l; i++)
        for (j = 0; j < c; j++)
            adj[i][j] = val;
    return (adj);
}

Graph GRAPHinit(int V) {
    Graph G = malloc(sizeof(struct graph));
    G->V = V;
    G->A = 0;
    G->adj = MATRIXinit(V, V, 0);
    return (G);
}

void GRAPHinsertArc(Graph G, vertex v, vertex w) {
    if (v != w) {
        if (G->adj[v][w] == 0) {
            G->adj[v][w] = 1;
            G->A++;
        }
    }
}

void GRAPHremoveArc(Graph G, vertex v, vertex w) {
    if (G->adj[v][w] == 1) {
        G->adj[v][w] = 0;
        G->A--;
    }
}

void GRAPHshow(Graph G) {
    vertex i, j;
    for (i = 0; i < G->V; i++) {
        printf("%2d:", i);
        for (j = 0; j < G->V; j++)
            if (G->adj[i][j] == 1)
                printf(" %2d", j);
        printf("\n");
    }
}

void GRAPHdestroy(Graph G) {
    vertex i;
    for (i = 0; i < G->V; i++)
        free(G->adj[i]);
    free(G->adj);
    free(G);
}


