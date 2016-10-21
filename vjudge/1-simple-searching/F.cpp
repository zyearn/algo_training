#include <iostream>
#include <queue>
#include <cstdlib>
#include <set>
#include <cstdio>
using namespace std;

struct Node {
    int n;
    int p;

    Node(int nn, int np) {
        n = nn;
        p = np;
    }
};

inline bool isPrime(int a) {
    for (int i=2; i*i<=a; i++) {
        if (a%i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    int s, e;
    for (int i=0; i<n; i++) {
        cin >> s >> e;

        char buf[10];
        set<int> ps;
        queue<Node> q;
        q.push(Node(s, 0));
        ps.insert(s);
        
        while (!q.empty()) {
            Node top = q.front();
            q.pop();

            if (top.n == e) {
                cout << top.p << endl;
                break;
            }

            sprintf(buf, "%04d", top.n);
            int ni;
            for (int j=0; j<4; j++) {
                for (int k=1; k<10; k++) {
                    buf[j] = (buf[j] - '0' + 1) % 10 + '0';
                    if (j == 0 && buf[j] == '0') continue;
                    ni = atoi(buf);
                    if (ps.find(ni) == ps.end() && isPrime(ni)) {
                        q.push(Node(ni, top.p + 1));
                        ps.insert(ni);
                    }
                }

                // 复原
                buf[j] = (buf[j] - '0' + 1) % 10 + '0';
            }
        }
    }
}
