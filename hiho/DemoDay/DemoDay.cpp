#include <cstdio>
#include <iostream>
using namespace std;

char maze[128][128];
int n, m;
int res = ~(1<<31);
int curmax = 0;

void backtrace(int i, int j, int curmax) {
    if (i >= n || j >= m) {
        return;
    }
    
    for (; j+1<m; j++) {
        if (maze[i][j+1] == 'b') {
            backtrace(i, j+1, curmax+1);
            for (; i+1<n; i++) {
                if (maze[i+1][j] == 'b') {
                    backtrace(i, j+1, curmax+1);
                    curmax++;
                }

            }
        }
    }

    if (i == n-1 && j == m-1) {
        res = min(res, curmax);
        return;
    }
}

int main() {
    int b;
    scanf("%d %d\n", &n, &m);

    for (int i=0; i<n; i++) {
        fgets(maze[i], 128, stdin);
    }

    if (maze[0][0] == 'b') curmax = 1;

    backtrace(0, 0, curmax);
    printf("%d\n", res);
}
