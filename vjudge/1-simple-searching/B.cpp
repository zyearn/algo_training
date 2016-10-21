#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

struct Node {
    int l, r, c;
    int sp;

    Node(int ll, int lr, int lc, int lsp) {
        l = ll;
        r = lr;
        c = lc;
        sp = lsp;
    }
};

char s[30][30][30];
int sp[30][30][30];
int l, r, c;
int sl, sr, sc;
int el, er, ec;
int dx[] = {0, 0, 1,-1, 0, 0};
int dy[] = {0, 0, 0, 0, 1,-1};
int dl[] = {1, -1,0, 0, 0, 0};

inline bool isOk(int ll, int lr, int lc) {
    return (ll >= 0 && ll < l) && (lr >=0 && lr < r) && (lc >=0 && lc < c) && s[ll][lr][lc] != '#';
}

int main() {
    while (cin >> l >> r >> c && l != 0 && r != 0 && c != 0) {
        for (int i=0; i<l ;i++) {
            for (int j=0; j<r; j++) {
                for (int k=0; k<c; k++) {
                    cin >> s[i][j][k];
                    if (s[i][j][k] == 'S') {
                        sl = i; sr = j; sc = k;
                    }

                    if (s[i][j][k] == 'E') {
                        el = i; er = j; ec = k;
                    }

                    sp[i][j][k] = ~(1<<31);
                }
            }
        }

        sp[sl][sr][sc] = 0;
        queue<Node> q;
        q.push(Node(sl, sr, sc , 0));

        while (!q.empty()) {
            Node node = q.front();
            q.pop();

            for (int i=0; i<6; i++) {
                int newl = node.l + dl[i];
                int newr = node.r + dx[i];
                int newc = node.c + dy[i];
                if (isOk(newl, newr, newc) && node.sp + 1 < sp[newl][newr][newc]) {
                    sp[newl][newr][newc] = node.sp + 1;
                    q.push(Node(newl, newr, newc, node.sp+1));
                }
            }
        }

        if (sp[el][er][ec] == ~(1<<31)) {
            printf("Trapped!\n");
        } else {
            printf("Escaped in %d minute(s).\n", sp[el][er][ec]);
        }

    }

    return 0;
}
