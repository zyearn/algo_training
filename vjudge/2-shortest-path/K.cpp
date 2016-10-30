/*
 * Author: Jiashun Zhu
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <vector>
#include <map>
#include <stack>
#include <climits>
using namespace std;

#define NODESNUM 1000000
#define EDGESNUM 2000000

struct Edge {
    int to, weight;
    int next;
};

int nodes[NODESNUM];
Edge edges[EDGESNUM];
int cur_e = 1;

int dist[NODESNUM];
int visited[NODESNUM];

int N, M;

inline void addEdge(int u, int v, int w) {
    if (u >= NODESNUM || v >= NODESNUM) return;

    edges[cur_e].to = v;
    edges[cur_e].weight = w;
    edges[cur_e].next = nodes[u];
    nodes[u] = cur_e++;
    return;
}

int main() {
    scanf("%d%d", &N, &M);
    int u, v, w;

    for (int i=0; i<M; i++) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }

    for (int i=1; i<=N; i++) {
        dist[i] = INT_MAX;
    }

    dist[1] = 0;
    visited[1] = 1;
    stack<int> st;
    st.push(1);

    while (!st.empty()) {
        int x = st.top();
        st.pop();
        visited[x] = 0;

        for (int pe = nodes[x]; pe!=0; pe=edges[pe].next) {
            Edge &e = edges[pe];
            if (dist[x] + e.weight < dist[e.to]) {
                dist[e.to] = dist[x] + e.weight;
                
                if (!visited[e.to]) {
                    st.push(e.to);
                    visited[e.to] = 1;
                }
            }
        }
    }

    cout << dist[N];
    return 0;
}
