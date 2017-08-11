#ifndef GRAPHmatrix_h
#define GRAPHmatrix_h

#define vertex int

struct graph {
    int V;
    int A;
    int **adj;
};
typedef struct graph *Graph;

static int **MATRIXinit(int, int, int);
Graph GRAPHinit(int); 
void GRAPHinsertArc(Graph, vertex, vertex);
void GRAPHremoveArc(Graph, vertex, vertex);
void GRAPHshow(Graph); 

#endif

