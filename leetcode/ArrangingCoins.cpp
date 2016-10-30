#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        double k = (-1 + sqrt(1 + 8.0*n)) / 2.0;
        return floor(k);
    }
};

int main() {
    Solution s;
    cout << s.arrangeCoins(1804289383) << endl;
}
