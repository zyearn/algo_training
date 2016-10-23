#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

int m, n;
char g[101][101];
int v[101][101];

void dfs(int i, int j) {
    int di[] = {0, 0, -1, 1, -1, -1, 1, 1};
    int dj[] = {1, -1, 0, 0, -1, 1, -1, 1};
    v[i][j] = 1;

    for (int k=0; k<8; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];

        if (ni >= 0 && ni < m && nj >= 0 && nj < n && !v[ni][nj] && g[ni][nj] == '@') {
            dfs(ni, nj);
        }
    }
}

int main() {
    while (cin >> m >> n && m != 0 && n != 0) {
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cin >> g[i][j];
            }
        }

        memset(v, 0, sizeof(v));

        int round = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (g[i][j] == '@' && !v[i][j]) {
                    dfs(i, j);
                    round++;
                }
            }
        }

        cout << round << endl;
    }
    
    return 0;
}
