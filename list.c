#include "GRAPH.h"

#include <stdlib.h>
#include <stdio.h>
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

Graph GRAPHinit(int V) {
    vertex i;
    Graph G = malloc(sizeof (struct graph));
    G->V = V;
    G->A = 0;
    G->adj = malloc(V * sizeof (link));
    for (i = 0; i < V; i++)
        G->adj[i] = NULL;
    return (G);
}

static link NEWnode(vertex v, link next) {
    link t = malloc(sizeof (struct node));
    t->w = v;
    t->next = next;
    return (t);
}

void GRAPHinsertArc(Graph G, vertex v, vertex w) {
    link p;
    if (v != w) {
        for (p = G->adj[v]; p != NULL && p->w != w; p = p->next);
        if (p == NULL) {
            G->adj[v] = NEWnode(w, G->adj[v]);
            G->A++;
        }
    }
}

void GRAPHremoveArc(Graph G, vertex v, vertex w) {
    link p, ant;
    for (p = G->adj[v], ant = NULL; p != NULL && p->w != w; ant = p, p = p->next);
    if (p != NULL) {
        if (ant == NULL)
            G->adj[v] = p->next;
        else 
            ant->next = p->next;
        free(p);
        G->A--;
    }
}

void GRAPHshow(Graph G) {
    vertex v;
    link w;
    for (v = 0; v < G->V; v++) {
        printf("%2d:", v);
        for (w = G->adj[v]; w != NULL; w = w->next)
            printf(" %2d", w->w);
        printf("\n");
    }
}

int GRAPHnumA(Graph G) {
    return G->A;
}

int GRAPHnumV(Graph G) {
    return G->V;
}

