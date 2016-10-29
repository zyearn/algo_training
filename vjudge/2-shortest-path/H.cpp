#include <iostream>
#include <cstdio>
using namespace std;

int N, M;
bool v[200][200];

int main() {
    cin >> N >> M;

    int a, b;
    for (int i=0; i<M; i++) {
        cin >> a >> b;
        v[a][b] = 1;
    }

    // Floyd
    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (k == i || k == j) continue;
                if (!v[i][j]) v[i][j] = v[i][k] && v[k][j];
            }
        }
    }

    int ans = 0;
    for (int i=1; i<=N; i++) {
        int count = 0;

        for (int j=1; j<=N; j++) {
            if (i == j) continue;

            if (v[i][j]) count++;
            if (v[j][i]) count++;
        }

        if (count == N-1) {
            ans++;
        }
    }

    cout << ans;
}
