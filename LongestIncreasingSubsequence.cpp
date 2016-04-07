class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        size_t sz = nums.size();
        if (sz == 0) return 0;
        
        vector<int> res(sz);
        int resmax = 1;
        int curmax;

        res[0] = 1;
        for (int i=1; i<sz; i++) {
            curmax = 1;
            for (int j=i-1; j>=0; j--) {
                if (nums[j] < nums[i]) {
                    curmax = max(curmax, res[j] + 1);
                }
            }

            res[i] = curmax;
            resmax = max(curmax, resmax);
        }

        return resmax;
    }
};
