#include "GRAPHmatrix.h"
#include <stdio.h>

int main() {
    int n;
    scanf(" %d", &n);
    Graph G = GRAPHinit(1<<n);
    for (int i = 0; i < (1<<n); i++)
        for (int j = 1; j < (1<<n); j += j)
            GRAPHinsertArc(G, i, i|j);
    printf("%d %d\n", G->V, G->A);
    GRAPHshow(G);
    for (int i = 0; i < 1<<n; i++)
        for (int j = 0; j < 1<<n; j++)
            GRAPHremoveArc(G, i, j);
    printf("%d %d\n", G->V, G->A);
    GRAPHshow(G);
    return 0;
}


