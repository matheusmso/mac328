/* Matheus de Mello Santos Oliveira - 8642821
 * MAC0328 - Algoritmos em grafos */

#include "list.h"
#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxV 10000
#define INF 0x3f3f3f3f

double sizeOfEdges[] = {0.2, 0.5, 1, 2, 5, 10, 20};
int dist[maxV][maxV];
double a[maxV];

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

double GRAPHbfs(Graph G) {
    int avg = 0;
    vertex v, s, u;
    link p;
    for (s = 0; s < G->V; s++) {
        for (v = 0; v < G->V; v++)
            dist[s][v] = INF;
        dist[s][s] = 0;
        QUEUEinit();
        QUEUEinsert(s);
        while (!QUEUEempty()) {
            u = QUEUEpop();
            for (p = G->adj[u]; p != NULL; p = p->next) {
                if (dist[s][p->w] == INF) {
                    dist[s][p->w] = dist[s][u]+1;
                    QUEUEinsert(p->w);
                }
            }
        }
    }
    /*GRAPHshow(G);
    for (v = 0; v < G->V; v++) {
        for (u = 0; u < G->V; u++) {
            printf("%2d ", dist[v][u] == INF ? -1 : dist[v][u]);
        }
        printf("\n");
    }
    printf("------------------\n");*/
    for (v = 0; v < G->V; v++)
        for (u = v+1; u < G->V; u++)
            if (dist[v][u] != INF)
                avg += dist[v][u];
    return (double)avg/((G->V*(G->V-1))/2);
}

int main(int argc, char* argv[]) {
    int vertices = atoi(argv[1]);
    int testes = atoi(argv[2]);
    int i, j, edges;
    double avg;
    for (j = 0; j < 7; j++) {
        edges = floor(sizeOfEdges[j]*vertices);
        if (edges > (vertices*(vertices-1))/2)
            break;
        printf("%d vertices e %d arestas\n", vertices, edges);
        for (i = 0; i < testes; i++) {
            Graph G = UGRAPHrand2(vertices, edges);
            a[i] = GRAPHbfs(G);
            GRAPHdestroy(G);
        }
        avg = 0.0;
        for (i = 0; i < testes; i++)
            avg += a[i];
        printf("%f\n", avg/testes);
    }
    return 0;
}

