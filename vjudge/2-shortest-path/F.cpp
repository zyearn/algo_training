#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

struct Edge {
    int from, to;
    int c;
};

Edge edges[30000];
int cur_e;
int dist[10000];

int F;
int N, M, W;

bool BellmanFord() {
    for (int i=1; i<=N; i++) dist[i] = INT_MAX;
    dist[1] = 0;

    for (int i=1; i<N; i++) {
        bool isChanged = false;
        for (int j=0; j<cur_e; j++) {
            Edge e = edges[j];

            if ((dist[e.from] != INT_MAX) && dist[e.to] > dist[e.from] + e.c) {
                dist[e.to] = dist[e.from] + e.c;
                isChanged = true;
            }
        }

        if (!isChanged) break;
    }

    for (int j=0; j<cur_e; j++) {
        Edge e = edges[j];
        if ((dist[e.from] != INT_MAX) && dist[e.to] > dist[e.from] + e.c) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> F;
    for (int f=1; f<=F; f++) {
        cin >> N >> M >> W;

        int s, e, t;
        cur_e = 0;
        for (int i=0; i<M; i++) {
            cin >> s >> e >> t;
            edges[cur_e].from = s;
            edges[cur_e].to = e;
            edges[cur_e].c = t;
            cur_e++;

            edges[cur_e].from = e;
            edges[cur_e].to = s;
            edges[cur_e].c = t;
            cur_e++;
        }

        for (int i=0; i<W; i++) {
            cin >> s >> e >> t;
            edges[cur_e].from = s;
            edges[cur_e].to = e;
            edges[cur_e].c = -t;
            cur_e++;
        }

        bool found = false;
        if (BellmanFord()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
