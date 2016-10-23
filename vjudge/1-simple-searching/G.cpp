#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

string s1, s2, r, t;
int c;
int n;

int main() {
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> c>> s1 >> s2 >> t;

        set<string> checked;
        r = s1+s2;

        int count = 0;
        while (true) {
            if (r == t) {
                cout << i+1 << " " << count << endl; 
                break;
            }

            if (checked.find(r) != checked.end()) {
                cout << i+1 << " -1" << endl;
                break;
            }

            checked.insert(r);
            count++;

            int j = 0; int k = r.size()/2;
            string tmpr(r.size(), 0);
            for (int q=0; j<r.size()/2; j++, k++) {
                tmpr[q++] = r[k];
                tmpr[q++] = r[j];
            }

            r = tmpr;
        }
    }
}
