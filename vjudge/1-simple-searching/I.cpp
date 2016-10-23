#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char g[11][11];
int round;

int fi, fj;
int fd;
int n, m;

struct Point {
    int x, y;
    int d;

    Point(){}
    Point(int xx, int yy, int dd) {
        x = xx;
        y = yy;
        d = dd;
    }
};

void bfs(int i, int j, vector<vector<int> > &v, int cur) {
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    queue<Point> q;
    q.push(Point(i, j, 0));
    
    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        if (v[p.x][p.y]) continue;
        v[p.x][p.y] = 1;
        if (p.d > fd) {
            fi = p.x;
            fj = p.y;
            fd = p.d;
        }

        for (int k=0; k<4; k++) {
            int ni = p.x + dx[k];
            int nj = p.y + dy[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !v[ni][nj] && g[ni][nj] == '#') {
                q.push(Point(ni, nj, p.d+1));
            }
        }
    }

}

int main() {
    int t;
    cin >> t;


    for (int tt=1; tt<=t; tt++) {
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> g[i][j];
            }
        }


        int res = 0;
        bool found = true;
        vector<int> av(2, 0);

        vector<vector<int> > visited(11, vector<int>(11, 0));
        round = 0;

        printf("Case %d: ", tt);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (visited[i][j] || g[i][j] == '.') continue;

                if (round >= 2) {
                    found = false;
                    break;
                }

                fd = -1;
                bfs(i, j, visited, 0);
                cout << "fi fj fd = " << fi << " " << fj << " " << fd << endl;

                vector<vector<int> > nv(11, vector<int>(11, 0));
                fd = -1;
                bfs(fi, fj, nv, 0);

                av[round] = fd;
                round++;
            }

            if (!found) {
                break;
            }
        }

        if (!found) {
            printf("-1\n");
        } else if (round == 0) {
            printf("0\n");
        } else if (round == 1) {
            printf("%d\n", (av[0]+2)/4);
            cout << round << " av[0] = " << av[0] << endl;
        } else {
            printf("%d\n", max((av[0]+1)/2, (av[1]+1)/2));
            cout << round << endl;
        }
    }

    return 0;
}
