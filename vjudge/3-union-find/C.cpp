#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

#define MAXN 30010

int f[MAXN];
int rk[MAXN];
int parts;

void init(int n) {
    for (int i=0; i<n; i++) {
        f[i] = i;
        rk[i] = 0;
    }
    parts = n;
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

    parts--;
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

int buf[MAXN];

int main() {
    int T;
    int N, M;
    int a, b;

    cin >> T;
    for (int t=0; t<T; t++) {
        scanf("%d%d", &N, &M);
        init(N);

        for (int m=0; m<M; m++) {
            scanf("%d%d", &a, &b);
            a--;b--;
            Union(a, b);
        }

        printf("%d\n", parts);
    }

}
