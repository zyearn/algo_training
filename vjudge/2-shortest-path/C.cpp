/*
 * Author: Jiashun Zhu
 */

/*
 * B题和C题都是Dijkstra的变形
 * B题求a到b的所有路径中，使得最大跳*最小*，用最小化堆
 * C题求a到b的所有路径中，使得最小跳*做大*，用最大化堆
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
        return a.d < b.d;
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

    Node *pv = &nodes[v];
    Edge *vu = &edges[cur_e++];
    vu->to = u;
    vu->weight = w;
    vu->next = pv->e;
    pv->e = vu;

    return;
}

int main() {
    int T;
    cin >> T;

    for (int i=1; i<=T; i++) {
        int n, m;
        cin >> n >> m;

        cur_e = 0;
        memset(nodes, 0, sizeof(nodes));
        memset(edges, 0, sizeof(edges));
        memset(dist, 0, sizeof(dist));
        memset(visited, 0, sizeof(visited));

        int a, b, w;
        for (int j=0; j<m; j++) {
            cin >> a >> b >> w;
            addEdge(a, b, w);
        }

        // 最大化堆
        priority_queue<Entry, vector<Entry>, Comp> pq;
        pq.push(Entry(1, INT_MAX));
        
        /*
         * 令dist[n]保存，从1到n使得最小边最大的那条路径中，最小边的数值
         */
        while (!pq.empty()) {
            Entry et = pq.top();
            pq.pop();
            if (visited[et.v]) continue;
            dist[et.v] = et.d;
            visited[et.v] = 1;
            
            for (Edge *e = nodes[et.v].e; e!=NULL; e=e->next) {
                int v = e->to;
                int w = e->weight;

                if (visited[v]) continue;

                int f = min(w, et.d);
                pq.push(Entry(v, f));
            }
        }

        cout << "Scenario #" << i << ":" << endl;
        cout << dist[n] << endl << endl;
    }

    return 0;
}
