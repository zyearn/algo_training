#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    struct mm {
        int i, j;
        int ni;
    };

    bool find132pattern(vector<int>& nums) {
        // dp[n]代表以a[0]...a[n]为输入时，nums[i], nums[j]为这个序列的范围(i<j)，ni为下一次可能成为i的下标
        vector<mm> dp(nums.size());

        if (nums.size() == 0) return false;

        dp[0].i = 0;
        dp[0].j = 0;
        dp[0].ni = 0;
        for (int i=1; i<nums.size(); i++) {
            dp[i] = dp[i-1];

            if (nums[i] < nums[dp[i-1].ni]) {
                // 如果当前数比潜在数ni小，更新ni
                dp[i].ni = i;
            } else if (nums[dp[i-1].j] - nums[dp[i-1].i] < nums[i] - nums[dp[i-1].ni]) {
                // 如果当前数与ni的范围差大于已知范围，更新范围
                dp[i].i = dp[i].ni;
                dp[i].j = i;
            }
        }

        for (int i=2; i<nums.size(); i++) {
            if (nums[i] > nums[dp[i-1].i] && nums[i] < nums[dp[i-1].j]) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> v{4,1,3,2};
    cout << s.find132pattern(v) << endl;

    return 0;
}
