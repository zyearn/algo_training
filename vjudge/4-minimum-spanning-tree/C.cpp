/*
 * Author: Jiashun Zhu
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define MAXN 30010
#define EPS 1e-8

struct Edge {
    int from, to;
    double w;

    Edge() {}
    Edge(int a, int b, double c) {
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

struct Point {
    double x,y,z,r;
};

Point ps[MAXN];
double res;

inline double dist(int i, int j) {
    double t = (ps[i].x - ps[j].x) * (ps[i].x - ps[j].x); 
    double p = (ps[i].y - ps[j].y) * (ps[i].y - ps[j].y); 
    double q = (ps[i].z - ps[j].z) * (ps[i].z - ps[j].z); 

    return sqrt(t + p + q);
}

inline bool overlap(int i, int j) {
    double d = dist(i, j);
    double r2 = ps[i].r + ps[j].r;

    return (d <= r2 + EPS);
}

int main() {
    while (cin >> N && N != 0) {
        priority_queue<Edge, vector<Edge>, Comp> q;
        init(N);
        res = 0;
        double w;

        for (int i=0; i<N; i++) {
            cin >> ps[i].x >> ps[i].y >> ps[i].z >> ps[i].r;

            for (int j=i-1; j>=0; j--) {
                if (overlap(i, j)) {
                    Union(i, j);
                }
            }
        }

        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (!Connected(i, j)) {
                    double d = dist(i, j);

                    q.push(Edge(i, j, dist(i, j) - ps[i].r - ps[j].r));
                }
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

        printf("%0.3lf\n", res);
    }

    return 0;
}
