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

#define MAXN 30010

struct Edge {
    int from, to;
    int w;

    Edge() {}
    Edge(int a, int b, int c) {
        from = a;
        to = b;
        w = c;
    }
};

struct Comp {
    bool operator()(const Edge&a, const Edge&b) {
        return a.w > b.w;
    }
};

int f[MAXN];
int rk[MAXN];

void init(int n) {
    for (int i=0; i<n; i++) {
        f[i] = i;
        rk[i] = 0;
    }
}

int Find(int x) {
    if (x != f[x]) {
        return f[x] = Find(f[x]);
    } else {
        return x;
    }
}

void Union(int a, int b) {
    int roota = Find(a);
    int rootb = Find(b);
    if (roota == rootb) return;

    if (rk[roota] < rk[rootb]) f[roota] = rootb;
    else if (rk[roota] > rk[rootb]) f[rootb] = roota;
    else {
        f[rootb] = roota;
        rk[roota]++;
    }
}

bool Connected(int a, int b) {
    return Find(a) == Find(b);
}

int N;
int vis[30];

int main() {
    char from, to;
    int k, w;
    while (cin >> N && N != 0) {
        memset(vis, 0, sizeof(vis));
        int cur = 0;
        int res = 0;
        priority_queue<Edge, vector<Edge>, Comp> q;
        init(30);

        for (int i=1; i<N; i++) {
            cin >> from >> k;
            for (int i=0; i<k; i++) {
                cin >> to >> w;
                q.push(Edge(from-'A', to-'A', w));
            }
        }

        while (!q.empty()) {
            Edge e = q.top();
            q.pop();

            if (Connected(e.from, e.to)) {
                continue;
            }

            Union(e.from, e.to);
            res += e.w;
        }

        printf("%d\n", res);
    }

    return 0;
}
