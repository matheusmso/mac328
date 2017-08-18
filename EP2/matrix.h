#ifndef MATRIX_H
#define MATRIX_H

#define vertex int

typedef struct graph *Graph;
struct graph {
    int V;
    int A;
    vertex **adj;
};

Graph GRAPHinit(int);  

void GRAPHinsertArc(Graph, vertex, vertex); 
void GRAPHremoveArc(Graph, vertex, vertex);
void GRAPHshow(Graph);
void GRAPHdestroy(Graph);

#endif  /*MATRIX_H*/
