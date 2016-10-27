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

int E, N;

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

inline void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
    return;
}

int main() {
    cin >> E >> N;
    map<int, int> m;

    int u, v, w;
    int uv;
    for (int i=0; i<E; i++) {
        cin >> u >> v >> w;
        if (u > v) swap(u, v);
        
        uv = u*10000 + v;
        if (m.find(uv) == m.end()) {
            m[uv] = w;
        } else {
            if (w < m[uv]) {
                m[uv] = w;
            }
        }
    }

    for (map<int,int>::iterator it=m.begin(); it!=m.end(); it++) {
        u = it->first / 10000;
        v = it->first % 10000;
        addEdge(u, v, it->second);
    }

    priority_queue<Entry, vector<Entry>, Comp> pq;
    pq.push(Entry(N, 0));
    
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

    cout << dist[1] << endl;

    return 0;
}
