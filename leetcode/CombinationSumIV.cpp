#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> ans(target + 1, 0);
        ans[0] = 1;

        for (int i=1; i<=target; i++) {
            for (int j=0; j<nums.size(); j++) {
                if (nums[j] > i) {
                    continue;
                }

                ans[i] += ans[i-nums[j]];
            }
        }

        return ans[target];
    }
};

int main() {
    Solution s;
    vector<int> v{1,2,3};
    cout << s.combinationSum4(v, 4) << endl;
}
