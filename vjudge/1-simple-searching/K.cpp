#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
using namespace std;

int maze[5][5];
int visited[5][5];
int pv[25];

struct Point {
    int i, j;
    Point(){}
    Point(int x, int y) {
        i = x;
        j = y;
    }
};

int main() {
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) {
        cin >> maze[i][j];
    }

    queue<Point> q;
    q.push(Point(0, 0));
    visited[0][0] = 1;

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int ni = p.i + dx[i];
            int nj = p.j + dy[i];

            if (ni >= 0 && ni < 5 && nj >= 0 && nj < 5 && !visited[ni][nj] && maze[ni][nj] == 0) {
                visited[ni][nj] = 1;
                q.push(Point(ni, nj));
                pv[ni*5 + nj] = p.i*5+p.j;
            }
        } 
    }

    stack<string> res;
    res.push("(4, 4)");
    int ci = 4, cj = 4;

    while (true) {
        int ni = pv[ci*5 + cj] / 5;
        int nj = pv[ci*5 + cj] % 5;
        char buf[20];
        sprintf(buf, "(%d, %d)", ni, nj);
        res.push(string(buf));
        ci = ni;
        cj = nj;

        if (ni == 0 && nj == 0) break;
    }

    while (!res.empty()) {
        cout << res.top() << endl;
        res.pop();
    }
}
