#include <iostream>
#include <cinttypes>
using namespace std;

class Solution {
public:
    // calculate mCn
    int C(int m, int n) {
        if (m < 0 || n < 0 || n > m) {
            return 0;
        }

        n = (n < (m-n)) ? n : (m-n);

        uint64_t sum = 1;
        for (int i=0; i<n; i++) {
            sum *= m;
            m--;
        }
        
        for (int i=n; i>0; i--) {
            sum /= i;
        }
        
        return sum;
    }

    int uniquePaths(int m, int n) {
        m = m - 1;
        n = n - 1;

        if (m < 0 || n < 0) {
            return 0;
        }

        int s = m + n;
        return C(s, m);
    }
};

int main() {
    Solution s;
    s.uniquePaths(10, 10);
    
    return 0;
}
