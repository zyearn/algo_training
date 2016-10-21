#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int M, N;
int a[16][16];
int flip[16][16];
int ans[16][16];

// 没有下
int dx[] = {0, 0, 1, -1, 0};
int dy[] = {1, -1, 0, 0, 0};

int get(int i, int j) {
    int res = a[i][j];

    int ni, nj;
    for (int k=0; k<5; k++) {
        ni = i + dy[k];
        nj = j + dx[k];

        if (ni >= 0 && ni < M && nj >= 0 && nj < N) {
            res += flip[ni][nj];
        }
    }

    return res % 2;
}

int solve() {
    for (int i=1; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (get(i-1, j) != 0) {
                flip[i][j]++;
            }
        } 
    }

    for (int j=0; j<N; j++) {
        if (get(M-1, j) != 0) {
            return -1;
        }
    }

    int res = 0;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            res += flip[i][j];
        }
    }

    return res;
}

int main() {
    
    while (cin >> M >> N) {

        for (int i=0; i<M; i++) for (int j=0; j<N; j++) {
            cin >> a[i][j];
        }

        int res = -1;
        for (int i=0; i<(1<<N); i++) {
            memset(flip, 0, sizeof(flip));
            for (int j=0; j<N; j++) {
                flip[0][N-1-j] = (i>>j) & 1;
            }

            int curRes = solve();
            if (curRes >= 0 && (res < 0 || curRes < res)) {
                res = curRes;
                memcpy(ans, flip, sizeof(flip));
            }
        }

        if (res < 0) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for (int i=0; i<M; i++) {
                for (int j=0; j<N; j++) {
                    if (j != 0) {
                        cout << " ";
                    }
                    cout << ans[i][j];
                }
                cout << endl;
            }
        }
    }

    return 0;
}