#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int f[100001];

int main() {
    int N, K;
    cin >> N >> K;
    for (int i=0; i<100001; i++) {
        f[i] = ~(1<<31);
    }

    f[N] = 0;
    queue<int> q;
    q.push(N);

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        if ((n-1 >= 0) && f[n] + 1 < f[n-1]) {
            f[n-1] = f[n] + 1;
            q.push(n-1);
        }
        if ((n+1 < 100001) && f[n] + 1 < f[n+1]) {
            f[n+1] = f[n] + 1;
            q.push(n+1);
        }
        if ((2*n < 100001) && f[n] + 1 < f[2*n]) {
            f[2*n] = f[n] + 1;
            q.push(2*n);
        }
    }

    printf("%d", f[K]);
}
