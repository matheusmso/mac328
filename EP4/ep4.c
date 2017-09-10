/* Matheus de Mello Santos Oliveira - 8642821
 * MAC0328 - Algoritmos em grafos */

#include "list.h"
#include "bridge.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int n, m, i;
    Graph G;
    vertex x, y;
    FILE *in = fopen(argv[1], "r");
    fscanf(in, " %d %d", &n, &m);
    G = GRAPHinit(n);
    for (i = 0; i < m; i++) {
        fscanf(in, " %d %d", &x, &y);
        GRAPHinsertArc(G, x, y);
        GRAPHinsertArc(G, y, x);
    }
    fclose(in);
    UGRAPHbridges(G);
    return 0;
}


