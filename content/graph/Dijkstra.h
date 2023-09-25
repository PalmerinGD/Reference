/**
 * Author: Diego Palmerin
 * Date: 2023-09-24
 * License: CC0
 * Source: folklore
 * Description: Calcula la distancia minima de un nodo $s$ en un grafo ya sea dirigido o no dirigido, que no tenga aristas con pesos negativos. Los nodos que no fueron visitados tendran dist = inf;.
 * Time: $O(N \log N + M)$
 * Status: stress-tested
 */
#pragma once

typedef long long ll;
typedef pair<ll,int> pli;
typedef vector<ll> vl;
typedef vector<bool> vb;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
const ll inf = LLONG_MAX;
void dijkstra(vector<vector<pli>> & g, int s) {
    int n = (int)g.size();
    vl dis(n, inf);
    vb vis(n);
    pqg<pli> pq;
    pq.push({0,s}); dis[s] = 0;
    while(!pq.empty()) {
        int u; ll d;
        tie(d,u) = pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto& [w,v] : g[u]) {
           if(dis[v] > dis[u] + w) {
               dis[v] = dis[u] + w;
               pq.push({dis[v], v});
           }
        }
    }
    return dis;
}
