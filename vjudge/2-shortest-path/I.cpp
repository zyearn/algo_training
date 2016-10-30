#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int from, to;
    double r;
};

Edge edges[10000];
int cur_e;

double dist[1000];

int N, M;

bool BellmanFord(int i) {
    memset(dist, 0, sizeof(dist));
    dist[i] = 1;

    for (int i=1; i<=N; i++) {
        bool isChanged = false;
        for (int j=0; j<cur_e; j++) {
            Edge e = edges[j];

            if (dist[e.to] < dist[e.from] * e.r) {
                dist[e.to] = dist[e.from] * e.r;
                isChanged = true;
            }
        }

        if (!isChanged) break;
    }

    return dist[i] > 1;
}

int nn;

int main() {
    int t = 1;

    while (cin >> N && N != 0) {
        nn = 0;
        cur_e = 0;
        map<string, int> nodesmap;

        string curr;
        for (int i=0; i<N; i++) {
            cin >> curr;
            nodesmap[curr] = nn++;
        }

        cin >> M;
        string a, b;
        double r;
        for (int i=0; i<M; i++) {
            cin >> a >> r >> b;
            edges[cur_e].from = nodesmap[a];
            edges[cur_e].to = nodesmap[b];
            edges[cur_e].r = r;
            cur_e++;
        }

        printf("Case %d: ", t++);
        bool found = false;
        for (int i=0; i<N; i++) {
            if (BellmanFord(i)) {
                printf("Yes\n");
                found = true;
                break;
            }
        }
        if (!found) printf("No\n");
    }

    return 0;
}
