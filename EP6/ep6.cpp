/* Matheus de Mello Santos Oliveira - 8642821
   MAC0328 - Algoritmos em grafos */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
const int INF = 0x3f3f3f3f;
vector<int> adj[N];
int value[N], vertices, edges, dist[N], parent[N], s, t;

void dijkstra(int start) {
    dist[start] = value[start];
    parent[start] = start;
    priority_queue<pair<int, int>> pq; //max pq, inserimos -dist para
    pq.push({-dist[start], start});    //trabalhar como min pq
    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int v = p.second;
        int d = -p.first;
        if (d > dist[v]) continue;
        for (int u : adj[v]) {
            if (dist[v] + value[u] < dist[u]) {
                dist[u] = dist[v] + value[u];
                parent[u] = v;
                pq.push({-dist[u], u});
            }
        }
    }
}

int main(int argc, char *argv[]) {
    freopen(argv[1], "r", stdin);
    scanf(" %d %d", &vertices, &edges);
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < vertices; i++) {
        scanf(" %d", value+i);
        dist[i] = INF;
    }
    scanf(" %d %d", &s, &t);
    dijkstra(s);
    vector<int> path;
    if (dist[t] != INF) {
        printf("%d\n", dist[t]);
        int u = t;
        while (parent[u] != u) {
            path.push_back(u);
            u = parent[u];
        }
        path.push_back(u);
        for (int i = path.size()-1; i >= 0; i--)
            printf("%d ", path[i]);
        printf("\n");
    }
    else
        printf("Vertice nao atingivel por s\n");
    /*for (int i = 0; i < vertices; i++)
        printf("%d %d\n", i, dist[i]);
        printf("\n");*/
    return 0;
}
    
