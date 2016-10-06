class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        size_t sz = nums.size();

        for (size_t i=0; i<sz; i++) {
            if (m.find(nums[i]) != m.end() && (i - m[nums[i]]) <= k) {
                return true;
            }

            m[nums[i]] = i;
        }

        return false;
    }
};
