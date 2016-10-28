#include <iostream>
#include <cstdio>
using namespace std;

struct Edge {
    int from, to;
    double r, c;
};

Edge edges[1000];
double dist[1000];
int cur_e;

int N, M, S;
double V;

bool BellmanFord() {
    memset(dist, 0, sizeof(dist));
    dist[S] = V;

    for (int i=1; i<N; i++) {
        bool isChanged = false;
        for (int j=0; j<cur_e; j++) {
            Edge e = edges[j];

            if (dist[e.to] < (dist[e.from] - e.c) * e.r) {
                dist[e.to] = (dist[e.from] - e.c) * e.r;
                isChanged = true;
            }
        }

        if (!isChanged) break;
    }

    for (int j=0; j<cur_e; j++) {
        Edge e = edges[j];
        if (dist[e.to] < (dist[e.from] - e.c) * e.r) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> N >> M >> S >> V;

    int a, b;
    double rab, cab, rba, cba;
    for (int i=0; i<M; i++) {
        cin >> a >> b >> rab >> cab >> rba >> cba;

        edges[cur_e].from = a;
        edges[cur_e].to = b;
        edges[cur_e].r = rab;
        edges[cur_e].c = cab;
        cur_e++;

        edges[cur_e].from = b;
        edges[cur_e].to = a;
        edges[cur_e].r = rba;
        edges[cur_e].c = cba;
        cur_e++;
    }

    if (BellmanFord()) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
