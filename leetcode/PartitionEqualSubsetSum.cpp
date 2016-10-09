#include <map>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int size = nums.size();
        for (int i=0; i<size; i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        } 

        int W = sum/2;
        int *f = new int[W+1];
        for (int j=0; j<=W; j++) {
            f[j] = 0;
        }

        for (int i=1; i<=size; i++) {
            for (int j=W; j>=0; j--) {
                if (nums[i-1] > j) {
                    continue;
                }

                f[j] = max(f[j], f[j-nums[i-1]] + nums[i-1]);
            }
        }

        return (f[W] == W);

    }
};

int main() {
    vector<int> n1{1, 5, 11, 5};
    vector<int> n2{1, 2, 3, 5};

    Solution s;
    cout << s.canPartition(n1) << endl;
    cout << s.canPartition(n2) << endl;

    return 0;
}
