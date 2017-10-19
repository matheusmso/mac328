/* Matheus de Mello Santos Oliveira - 8642821
   MAC0328 - Algoritmos em grafos */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;

int visit[N], parent[N], color[N], match[N], n, m;
vector<int> adj[N];

void newMatching(int u) {
    int x;
    do {
        x = parent[u];
        match[u] = x;
        match[x] = u;
        u = parent[x];
    } while (u != x);
}

bool dfsRaugment(int u) {
    for (int v : adj[u]) {
        if (visit[v] == 0) {
            visit[v] = 1;
            parent[v] = u;
            if (match[v] == -1) {
                newMatching(v);
                return true;
            }
            int w = match[v];
            visit[w] = 1;
            parent[w] = v;
            if (dfsRaugment(w))
                return true;
        }
    }
    return false;
}

bool augmentMatching() {
    for (int v = 0; v < n; v++) visit[v] = 0;
    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && match[v] == -1 && visit[v] == 0) {
            visit[v] = 1;
            parent[v] = v;
            if (dfsRaugment(v))
                return true;
        }
    }
    return false;
}

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        match[i] = -1;
    int size = 0;
    while (augmentMatching()) size++;
    printf("%d\n", size);
    return 0;
}

