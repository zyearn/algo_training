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


int main() {
    int P, R;
    long long res;

    while (cin >> P && P != 0) {
        cin >> R;
        priority_queue<Edge, vector<Edge>, Comp> q;
        init(P);
        int a, b, w;
        res = 0;

        for (int i=0; i<R; i++) {
            cin >> a >> b >> w;
            a -= 1;
            b -= 1;
            q.push(Edge(a, b, w));
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

        printf("%lld\n", res);
    }

    return 0;
}
