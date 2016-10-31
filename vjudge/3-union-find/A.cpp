#include <iostream>
#include <cmath>
#include <set>
using namespace std;

#define MAXN 1020

int f[MAXN];
int rk[MAXN];
int N;

void init() {
    for (int i=1; i<=N; i++) {
        f[i] = i;
        rk[i] = 0;
    }
}

int Find(int x) {
    if (x <= 0 || x > N) {
        return -1;
    }

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

struct Point {
    int x, y;
};

Point p[MAXN];
int d;

int dist(Point &a, Point &b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}


int main() {
    cin >> N >> d;

    for (int i=1; i<=N; i++) {
        cin >> p[i].x >> p[i].y;
    }

    init();

    char cmd;
    int a, b;
    set<int> repaired;

    while (cin >> cmd) {
        if (cmd == 'O') {
            cin >> a;
            for (set<int>::iterator it=repaired.begin(); it!=repaired.end(); it++) {
                if (dist(p[a], p[*it]) <= d*d) {
                    Union(a, *it);
                }
            }
            repaired.insert(a);

        } else {
            cin >> a >> b;
            if (Connected(a, b)) {
                cout << "SUCCESS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
        }
    }

    return 0;
}
