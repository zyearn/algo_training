class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> m;
        size_t sz = nums.size();

        for (size_t i=0; i<sz; i++) {
            if (m.find(nums[i]) != m.end()) {
                return true;
            }

            m.insert(make_pair(nums[i], true));
        }

        return false;
    }
};
