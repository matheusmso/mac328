/* Matheus de Mello Santos Oliveira - 8642821
 * MAC0328 - Algoritmos em grafos */

#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxV 10000

int cc[maxV];
int ccSize[maxV];
double prob;

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
    prob = 0.0;
    for (i = 0; i < c; i++)
        prob += (ccSize[i]*(ccSize[i]-1))/2;
    prob /= ((G->V*(G->V-1))/2);
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
    int edges;
    int cap = vertices*(vertices-1);
    if (cap > 20*vertices) cap = 20*vertices;
    srand(time(NULL));
    for (edges = 0; edges <= cap; edges++) {
        int i;
        double probEmp = 0.0;
        for (i = 0; i < tests; i++) {
            Graph G = UGRAPHrand2(vertices, edges);
            GRAPHdfs(G);
            GRAPHdestroy(G);
            probEmp += prob;
        }
        /*printf("Para %d vertices e %d arestas temos probabilidade empirica de %f\n", 
          vertices, edges, probEmp/tests);*/
        printf("%d, %f\n", edges, probEmp/tests);
    }
    return 0;
}

