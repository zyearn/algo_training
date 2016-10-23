#include <iostream>
#include <queue>
#include <cstdlib>
#include <set>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

struct Node {
    int a, b;

    int type;
    int para;
    int prev;
    int count;
    int n;

    Node() {
    
    }

    Node(int pa, int pb, int pt, int ppa, int pp, int pc, int pn) {
        a = pa;
        b = pb;
        type = pt;
        para = ppa;
        prev = pp;
        count = pc;
        n = pn;
    }
};

Node node[10010];
int cur;

int A, B, C;

void output(Node nd, stack<string> &out) {
    int count = nd.count;
    for (int i=0; i<count; i++) {
        if (nd.type == 0) {
            if (nd.para == 0) out.push("FILL(1)"); 
            else out.push("FILL(2)");
        } else if (nd.type == 1) {
            if (nd.para == 0) out.push("DROP(1)");
            else out.push("DROP(2)");
        } else if (nd.type == 2) {
            if (nd.para == 0) out.push("POUR(1,2)");
            else out.push("POUR(2,1)");
        }

        nd = node[nd.prev];
    }
}


int main() {
    cin >> A >> B >> C;
    queue<Node> q;
    set<int> checked;

    node[cur] = Node(0, 0, -1, -1, -1, 0, 0);
    q.push(node[cur]);
    cur++;

    stack<string> out;
    bool found = false;
    while (!q.empty()) {
        Node nd = q.front();
        q.pop();

        if (nd.a == C || nd.b == C) {
            output(nd, out);
            found = true;
            break;
        }

        if (checked.find(nd.a * 1000 + nd.b) != checked.end()) {
            continue;
        }

        checked.insert(nd.a * 1000 + nd.b);

        // fill
        // Node(int pa, int pb, int pt, int ppa, int pp, int pc, int pn) {
        node[cur] = Node(A, nd.b, 0, 0, nd.n, nd.count+1, cur);
        q.push(node[cur]);
        cur++;

        node[cur] = Node(nd.a, B, 0, 1, nd.n, nd.count+1, cur);
        q.push(node[cur]);
        cur++;

        //drop
        node[cur] = Node(0, nd.b, 1, 0, nd.n, nd.count+1, cur);
        q.push(node[cur]);
        cur++;

        node[cur] = Node(nd.a, 0, 1, 1, nd.n, nd.count+1, cur);
        q.push(node[cur]);
        cur++;

        //POUR
        int m = min(nd.a, B-nd.b);
        node[cur] = Node(nd.a-m, nd.b+m, 2, 0, nd.n, nd.count+1, cur);
        q.push(node[cur]);
        cur++;

        m = min(A-nd.a, nd.b);
        node[cur] = Node(nd.a+m, nd.b-m, 2, 1, nd.n, nd.count+1, cur);
        q.push(node[cur]);
        cur++;
    }

    if (!found) {
        cout << "impossible";
    } else {
        cout << out.size() << endl;
        while (!out.empty()) {
            cout << out.top() << endl;
            out.pop();
        }
    }
    
}
