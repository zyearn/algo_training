#include <iostream>
#include <cmath>
#include <set>
using namespace std;

#define MAXN 30010

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

int buf[MAXN];

int main() {
    int n, m;
    int K;
    int t;

    while (cin >> n >> m && (m > 0 || n > 0)) {
        init(n);

        for (int i=0; i<m; i++) {
            scanf("%d", &K);
            for (int k=0; k<K; k++) scanf("%d", &buf[k]);
            for (int j=0; j<K; j++) for (int k=j+1; k<K; k++) Union(buf[j], buf[k]);
        }
        
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (Connected(0, i)) {
                ans++;
            }
        }

        printf("%d\n", ans);
    }

}
