#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

int main() {
    int n;
    while (cin >> n && n != 0) {
        queue<ll> q;
        q.push(1);

        while (true) {
            ll top = q.front();
            q.pop();

            if (top % n == 0) {
                cout << top << endl;
                break;
            }

            q.push(top*10);
            q.push(top*10 + 1);
        }
    }

    return 0;
}
