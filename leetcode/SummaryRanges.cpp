class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        size_t sz = nums.size();
        vector<string> res;

        size_t start, end;
        size_t i=0;

        while (i < sz) {
            start = end = i;

            while (end + 1 < sz && nums[end] + 1 == nums[end+1]) {
                end++;
            }
            
            if (start == end) {
                res.push_back(to_string(nums[start]));
            } else {
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            }

            i = end + 1;
        }
        
        return res;
    }
};
