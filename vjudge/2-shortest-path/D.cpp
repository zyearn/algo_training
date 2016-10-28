/*
 * Author: Jiashun Zhu
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
using namespace std;

struct Entry {
    int v;
    int d;

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

struct Edge {
    int to, weight;
    Edge *next;
};

struct Node {
    Edge *e;
};

#define NODESNUM 2000
#define EDGESNUM 2000000

Node nodes[NODESNUM];
Edge edges[EDGESNUM];
int cur_e;

int dist[NODESNUM];
int visited[NODESNUM];

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

int to[NODESNUM];
int go[NODESNUM];

int main() {
    int N, M, X;
    cin >> N >> M >> X;

    int a, b, t;
    for (int m=0; m<M; m++) {
        cin >> a >> b >> t;
        addEdge(a, b, t);
    }

    // 运行N次Dijkstra。以X为源点时需记下从X到所有点的距离（go数组）
    for (int i=1; i<=N; i++) {
        memset(visited, 0, sizeof(visited));

        priority_queue<Entry, vector<Entry>, Comp> pq;
        pq.push(Entry(i, 0));
        
        while (!pq.empty()) {
            Entry et = pq.top();
            pq.pop();

            if (visited[et.v]) continue;
            visited[et.v] = 1;

            if (et.v == X && i != X) {
                to[i] = et.d;
                break;
            } else if (i == X) {
                go[et.v] = et.d;
            }
            
            for (Edge *e = nodes[et.v].e; e!=NULL; e=e->next) {
                int v = e->to;
                int w = e->weight;

                if (visited[v]) continue;

                pq.push(Entry(v, et.d + w));
            }
        }
    }

    int ans = 0;
    for (int i=1; i<=N; i++) {
        int cur = to[i] + go[i];
        if (cur > ans) {
            ans = cur;
        }
    }

    cout << ans;

    return 0;
}
