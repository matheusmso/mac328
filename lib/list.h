#ifndef lists_h
#define lists_h

#define vertex int

typedef struct node *link;

struct node {
    int w;
    link next;
};

struct graph {
    int V;
    int A;
    link *adj;
};

typedef struct graph *Graph;

Graph GRAPHinit(int);  

void GRAPHinsertArc(Graph, vertex, vertex); 
void GRAPHremoveArc(Graph, vertex, vertex);
void GRAPHshow(Graph);
void GRAPHdestroy(Graph);

#endif /*LIST_H*/

