#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int max(int a, int b) {
        return (a>b)? a: b;
    }

    int rob(vector<int>& nums) {
        int size = nums.size();

        if (size == 0) return 0;
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);

        vector<int> res;
        res.push_back(nums[0]);
        res.push_back(max(nums[0], nums[1]));

        int curMax = nums[0];
        if (curMax < nums[1]) curMax = nums[1];

        int tmp;
        for (int i=2; i<size; i++) {
            tmp = max(res[i-2] + nums[i], res[i-1]);
            res.push_back(tmp);
            if (tmp > curMax) {
                curMax = tmp;
            }
        }

        return curMax;
    }
};

int main() {
    Solution s;
    vector<int> nums= {1,1,2,1};

    cout << s.rob(nums) << endl;
    return 0;
}
