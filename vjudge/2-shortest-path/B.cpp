/*
 * Author: Jiashun Zhu
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <limits>
#include <cmath>
#include <set>
using namespace std;

struct Entry {
    int i, j;
    double d;

    Entry() {}
    Entry(int ii, int jj, double dd) {
        i = ii;
        j = jj;
        d = dd;
    }
};

struct Comp {
    bool operator()(const Entry &a, const Entry &b) {
        return a.d > b.d;
    }
};

inline double distance(double i, double j, double p, double q) {
    return sqrt((i-p)*(i-p) + (j-q)*(j-q));
}

int main() {
    int n;
    int t = 1;

    while (cin >> n && n != 0) {
        int si, sj, ei, ej;
        cin >> si >> sj >> ei >> ej;

        set<pair<int ,int> > V;
        map<pair<int, int>, int> visited;
        map<pair<int, int>, double> dist;

        V.insert(pair<int, int>(si, sj));
        V.insert(pair<int, int>(ei, ej));

        int a, b;
        for (int i=2; i<n; i++) {
            cin >> a >> b;
            V.insert(pair<int, int>(a, b));
        }

        priority_queue<Entry, vector<Entry>, Comp> pq;
        pq.push(Entry(si, sj, 0));
        
        while (!pq.empty()) {
            Entry et = pq.top();
            pq.pop();
            if (visited[pair<int, int>(et.i, et.j)]) continue;

            dist[pair<int, int>(et.i, et.j)] = et.d;
            visited[pair<int, int>(et.i, et.j)] = 1;
            
            for (set<pair<int ,int> >::iterator it=V.begin(); it!=V.end(); it++) {
                int i = it->first;
                int j = it->second;

                if (visited[pair<int, int>(i, j)]) continue;

                double v = max(et.d, distance(i, j, et.i, et.j));
                pq.push(Entry(i, j, v));
            }
        }

        cout << "Scenario #" << t++ << endl;
        cout << "Frog Distance = ";
        printf("%0.3lf\n\n", dist[pair<int, int>(ei, ej)]);
    }

    return 0;
}
