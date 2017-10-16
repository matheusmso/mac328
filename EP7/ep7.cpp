/* Matheus de Mello Santos Oliveira - 8642821
   MAC0328 - Algoritmos em grafos */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
vector<int> adj[N], color;
int n, m, k;

bool go(int v) {
    if (v == n) {
        vector<int> used(k, 0);
        for (int i = 0; i < n; i++)
            used[color[i]] = 1;
        int cnt = 0;
        for (int i = 0; i < k; i++)
            if (used[color[i]])
                cnt++;
        if (cnt <= k)
            return true;
        return false;
    }
    vector<int> used(k, 0);
    for (int w : adj[v])
        if (color[w] != -1)
            used[color[w]] = 1;
    for (int i = 0; i < k; i++) {
        if (used[i] == 0) {
            color[v] = i;
            if (go(v+1))
                return true;
            color[v] = -1;
        }
    }
    return false;
}

void UGRAPHrand2(int V, int A) {
    double p = (double)2*A/V/(V-1);
    for (int v = 0; v < V; v++) {
        for (int w = v+1; w < V; w++) {
            if (rand() < p*(RAND_MAX+1.0)) {
                adj[v].push_back(w);
                adj[w].push_back(v);
            }
        }
    }
}


int main(int argc, char* argv[]) {
    n = atoi(argv[1]);
    m = atoi(argv[2]);
    k = atoi(argv[3]);
    UGRAPHrand2(n, m);
    for (int i = 0; i < n; i++) {
        printf("%2d: ", i);
        for (int j : adj[i])
            printf("%2d ", j);
        printf("\n");
    }
    color.resize(n, -1);
    if (go(0)) {
        printf("Possível ser colorido com %d cores\n", k);
        for (int i = 0; i < n; i++)
            printf("%d %d\n", i, color[i]);
    }
    else
        printf("Impossível ser colorido com %d ores\n", k);
    return 0;
}
