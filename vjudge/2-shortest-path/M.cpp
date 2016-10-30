/*
 * Author: Jiashun Zhu
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

#define NODESNUM 3001
#define EDGESNUM 1000001

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
int canChange[NODESNUM];

int M, N;

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
    scanf("%d %d", &M, &N);
    map<int, int> values;
    map<int, int> lvl;

    int p, l, x;
    int d, w;
    for (int i=1; i<=N; i++) {
        scanf("%d%d%d", &p, &l, &x);
        values[i] = p;
        lvl[i] = l;

        for (int j=0; j<x; j++) {
            scanf("%d%d", &d, &w);
            addEdge(i, d, w);
        }
    }
    
    int res = INT_MAX;
    for (int m=0; m<=M; m++) {
        int l = lvl[1]-M+m;
        int h = lvl[1]+m;

        memset(canChange, 0, sizeof(canChange));
        for (int i=1; i<=N; i++) {
            if (lvl[i] >= l && lvl[i] <= h) 
                canChange[i] = 1;

            dist[i] = INT_MAX;
        }

        memset(visited, 0, sizeof(visited));

        priority_queue<Entry, vector<Entry>, Comp> pq;
        pq.push(Entry(1, 0));

        while (!pq.empty()) {
            Entry et = pq.top();
            pq.pop();
            if (visited[et.v]) continue;

            dist[et.v] = et.d;
            visited[et.v] = 1;

            for (Edge *pe = nodes[et.v].e; pe!=NULL; pe=pe->next) {
                if (visited[pe->to]) continue;
                if (!canChange[pe->to]) continue;

                pq.push(Entry(pe->to, pe->weight + et.d));
            }
        }

        int tmpans = INT_MAX;
        for (int i=1; i<=N; i++) {
            if (dist[i] != INT_MAX && values[i] + dist[i] < tmpans) {
                tmpans = values[i] + dist[i];
            }
        }

        res = (tmpans < res)?tmpans: res;
    }

    cout << res;

    return 0;
}
