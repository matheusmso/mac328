#ifndef GRAPH_H
#define GRAPH_H

#define vertex int

typedef struct graph *Graph;

Graph GRAPHinit(int);  

void GRAPHinsertArc(Graph, vertex, vertex); 
void GRAPHremoveArc(Graph, vertex, vertex);
void GRAPHshow(Graph);

int GRAPHnumA(Graph);
int GRAPHnumV(Graph);

#endif  /*GRAPH_H*/
