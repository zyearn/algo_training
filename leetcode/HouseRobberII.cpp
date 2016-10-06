#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int max(int a, int b) {
        return (a>b)? a: b;
    }

    int rob1(vector<int>& nums, int low, int high) {
        if (low > high) return 0;
        int size = high - low + 1;

        if (size == 0) return 0;
        if (size == 1) return nums[low];
        if (size == 2) return max(nums[low], nums[low+1]);

        int pprev = nums[low];
        int prev  = max(nums[low], nums[low+1]);

        int curMax = prev;
        int tmp;
        for (int i=low+2; i<=high; i++) {
            tmp = max(pprev + nums[i], prev);
            pprev = prev;
            prev = tmp;
            if (tmp > curMax) {
                curMax = tmp;
            }
        }

        return curMax;
    }

    int rob(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];

        return max(rob1(nums, 0, nums.size()-2), rob1(nums, 1, nums.size()-1));
    }
};

int main() {
    Solution s;
    vector<int> nums= {1,1,2,1};

    cout << s.rob(nums) << endl;
    return 0;
}
