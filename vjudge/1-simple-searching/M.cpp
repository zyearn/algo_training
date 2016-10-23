#include <iostream>
#include <queue>
#include <cstdlib>
#include <set>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

struct Node {
    int a, b, c;
    int d;

    Node() {}

    Node(int pa, int pb, int pc, int pd) {
        a = pa;
        b = pb;
        c = pc;
        d = pd;
    }
};

int A, B, C;

int main() {
    while (cin >> A >> B >> C && A!=0 && B!=0 && C!=0) {
        queue<Node> q;
        set<int> checked;

        if (A%2 == 1 || B==0 || C==0) {
            cout << "NO" << endl;
            continue;
        }

        q.push(Node(A, 0, 0, 0));
        bool found = false;
        int ans;

        while (!q.empty()) {
            Node nd = q.front();
            q.pop();

            if ((nd.a == A/2 && nd.b == A/2 && nd.c == 0) ||
                (nd.a == A/2 && nd.b == 0 && nd.c == A/2) || 
                (nd.a == 0 && nd.b == A/2 && nd.c == A/2)) {
                found = true;
                ans = nd.d;
                break;
            }

            if (checked.find(nd.a*10000 + nd.b*100 + nd.c) != checked.end()) {
                continue;
            }
            checked.insert(nd.a*10000 + nd.b*100 + nd.c);

            int m;
            // A->B,C
            m = min(nd.a, B-nd.b);
            q.push(Node(nd.a-m, nd.b+m, nd.c, nd.d+1));
            m = min(nd.a, C-nd.c);
            q.push(Node(nd.a-m, nd.b, nd.c+m, nd.d+1));

            //B->A,C
            m = min(nd.b, A-nd.a);
            q.push(Node(nd.a+m, nd.b-m, nd.c, nd.d+1));
            m = min(nd.b, C-nd.c);
            q.push(Node(nd.a, nd.b-m, nd.c+m, nd.d+1));

            //C->A,B
            m = min(nd.c, A-nd.a);
            q.push(Node(nd.a+m, nd.b, nd.c-m, nd.d+1));
            m = min(nd.c, B-nd.b);
            q.push(Node(nd.a, nd.b+m, nd.c-m, nd.d+1));
        }

        if (found) {
            cout << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
