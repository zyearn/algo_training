#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int min(int a, int b) {
        return (a<b)?a:b;
    }

    int numSquares(int n) {
        if (n < 0) return 0;

        static vector<int> res(1, 0);
        int curmin;

        for (int i=res.size(); i<n+1; i++) {
            curmin = ~(1<<31);

            for (int j=1; i - j*j >= 0; j++) {
                curmin = min(curmin, res[i-j*j]);
            }

            res.push_back(curmin + 1);
        }

        return res[n];
    }
};

int main() {
    Solution s;
    cout << s.numSquares(12);
}
