#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char s[8][8];
int n, k;
int c;
int col[8];

void dfs(int start, int rem) {
    for (int j=0; j<n; j++) {
        if (s[start][j] == '#' && !col[j]) {
            if (rem == 1) {
                c++;
            } else {
                col[j] = 1;
                for (int k=start+1; k<n-rem+2; k++) {
                    dfs(k, rem - 1);
                }
                col[j] = 0;
            }
        }
    }
    
}

int main() {
    while (cin >> n >> k && n != -1 && k != -1) {
        for (int i=0; i<n ;i++) {
            for (int j=0; j<n; j++) {
                cin >> s[i][j];
            }
        }

        c = 0;
        memset(col, 0, sizeof(col));

        for (int i=0; i<=n-k; i++) {
            dfs(i, k);
        }

        printf("%d\n", c);
    }
}
