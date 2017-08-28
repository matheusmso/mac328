/* Matheus de Mello Santos Oliveira - 8642821
 * MAC0328 - Algoritmos em grafos */

#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define maxV 10000

int cc[maxV];
int ccSize[maxV];
int ccOfSize[maxV];
double medges[] = {0.2, 0.5, 1, 2, 5, 10, 20};

void dfsR(Graph G, vertex v) {
    vertex w;
    for (w = 0; w < G->V; w++)
        if (G->adj[v][w] == 1 && cc[w] == -1) {
            cc[w] = cc[v];
            ccSize[cc[v]]++;
            dfsR(G, w);
        }
}

void GRAPHdfs(Graph G) {
    vertex v;
    int i;
    int c = 0;
    for (i = 0; i < G->V; i++) {
        cc[i] = -1;
        ccSize[i] = 0;
    }
    for (v = 0; v < G->V; v++)
        if (cc[v] == -1) {
            cc[v] = c++;
            ccSize[cc[v]]++;
            dfsR(G, v);
        }
    for (i = 0; i < c; i++)
        ccOfSize[ccSize[i]]++;
}

Graph UGRAPHrand2(int V, int A) {
    Graph G = GRAPHinit(V);
    double p = (double)2*A/V/(V-1);
    vertex v, w;
    for (v = 0; v < G->V; v++) {
        for (w = v+1; w < G->V; w++) {
            if (rand() < p*(RAND_MAX+1.0)) {
                GRAPHinsertArc(G, v, w);
                GRAPHinsertArc(G, w, v);
            }
        }
    }
    return G;
}

int main(int argc, char *argv[]) {
    int vertices = atoi(argv[1]);
    int tests = atoi(argv[2]);
    int m;
    srand(time(NULL));
    for (m = 0; m < 7; m++) {
        int i;
        int edges = floor(medges[m]*vertices);
        if (edges > (vertices*(vertices-1))/2)
            break;
        printf("%d arestas\n", edges);
        for (i = 0; i <= vertices; i++)
            ccOfSize[i] = 0;
        for (i = 0; i < tests; i++) {
            Graph G = UGRAPHrand2(vertices, edges);
            GRAPHdfs(G);
            GRAPHdestroy(G);
        }
        for (i = 1; i <= vertices; i++) {
            if (ccOfSize[i] == 0) continue;
            printf("%d, %f\n", i, (double)ccOfSize[i]/tests);
        }
    }
    return 0;
}

