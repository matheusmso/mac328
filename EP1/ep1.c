/* Matheus de Mello Santos Oliveira - 8642821
 * MAC0328 - Algoritmos em Grafos
 **/

#include "GRAPH.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

FILE *in = NULL;

/* Clears "3." from the beggining of the buffer*/
void trim() {
    char c;
    int i;
    for (i = 0; i < 2; i++) 
        fscanf(in, " %c", &c);
}

/*Size of the number k in decimal scale*/
int size(int k) {
    int ans = 0;
    while (k > 0) {
        k /= 10;
        ans++;
    }
    return ans;
}

/*Next number from the buffer with size step modulo k+1*/
int next(int step, int k) {
    char t[10];
    int i, aux;
    for (i = 0; i < 10; i++)
        t[i] = 0;
    for (i = 0; i < step; i++)
        if (fscanf(in, " %c", &t[i]) == EOF)
            return -1;
    aux = atoi(t)%(k+1);
    return aux;
}

/*Next number from the random generator*/
int nextrand(int k) {
    double r = rand()/(RAND_MAX+1.0);
    int aux = r*(k+1);
    return aux;
}

/*Run the buffer version*/
void run(char *ver, char *file) {
    int X = atoi(ver);
    int step = size(X);
    Graph G = GRAPHinit(X+1);
    int cur, last;
    int digits = step;
    in = fopen(file, "r");
    trim();
    last = next(step, X);
    while (1) {
        cur = next(step, X);
        if (cur == -1) {
            printf("Chegou no fim dos digitos :(\n");
            break;
        }
        GRAPHinsertArc(G, last, cur);
        last = cur;
        digits += step;
        if (GRAPHnumA(G) == (GRAPHnumV(G)-1)*GRAPHnumV(G)) {
            printf("# de vertices = %d\n", X+1);
            printf("# de digitos utilizados para gerar o grafo completo = %d\n", digits);
            break;
        }
    }
}

/*Run the random version*/
int runrand(char *ver) {
    int X = atoi(ver);
    Graph G = GRAPHinit(X+1);
    int cur, last;
    int step = size(X);
    int digits = step;
    last = nextrand(X);
    while (1) {
        cur = nextrand(X);
        GRAPHinsertArc(G, last, cur);
        last = cur;
        digits += step;
        if (GRAPHnumA(G) == (GRAPHnumV(G)-1)*GRAPHnumV(G)) {
            printf("# de vertices = %d\n", X+1);
            printf("# de digitos utilizados para gerar o grafo completo = %d\n", digits);
            return digits;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc == 3) run(argv[1], argv[2]);
    else {
        int i;
        int avg = 0;
        int T = atoi(argv[2]);
        srand(time(NULL));
        for (i = 0; i < T; i++)
            avg += runrand(argv[1]);
        printf("%d testes deram %d de media\n", T, avg/T);
    }
    return 0;
}

