/*
 * Author: Jiashun Zhu
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

#define NODESNUM 3001
#define EDGESNUM 10001

struct Edge {
    int to, weight;
    Edge *next;
};

struct Node {
    Edge *e;
};

struct Entry {
    int v, d;

    Entry() {}
    Entry(int vv, int dd) {
        v = vv;
        d = dd;
    }
};

struct Comp {
    bool operator()(const Entry &a, const Entry &b) {
        return a.d > b.d;
    }
};

Node nodes[NODESNUM];
Edge edges[EDGESNUM];
int cur_e;

int dist[NODESNUM];
int visited[NODESNUM];

int N, s, e;

inline void addEdge(int u, int v, int w) {
    if (u >= NODESNUM || v >= NODESNUM) return;

    Node *pu = &nodes[u];
    Edge *uv = &edges[cur_e++];
    uv->to = v;
    uv->weight = w;
    uv->next = pu->e;
    pu->e = uv;

    return;
}

int main() {
    cin >> N >> s >> e;

    int v, m;
    for (int i=1; i<=N; i++) {
        cin >> m;

        for (int j=0; j<m; j++) {
            cin >> v;
            if (j==0) addEdge(i, v, 0); 
            else addEdge(i, v, 1);
        }
    }

    priority_queue<Entry, vector<Entry>, Comp> pq;
    pq.push(Entry(s, 0));
    
    while (!pq.empty()) {
        Entry et = pq.top();
        pq.pop();
        if (visited[et.v]) continue;

        dist[et.v] = et.d;
        visited[et.v] = 1;

        for (Edge *pe = nodes[et.v].e; pe!=NULL; pe=pe->next) {
            if (!visited[pe->to]) {
                pq.push(Entry(pe->to, pe->weight + et.d));
            }
        }
    }

    if (visited[e]) cout << dist[e];
    else cout << "-1";

    return 0;
}
