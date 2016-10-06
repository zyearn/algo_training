class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int left, right;
        int res = 0;
        int curmax;

        for (size_t i=0; i<nums.size(); i++) {
            int &n = nums[i];

            if (m.find(n) == m.end()) {
                left = (m.find(n - 1) != m.end())? m[n - 1]: 0;
                right = (m.find(n + 1) != m.end())? m[n + 1]: 0;
                curmax = left + right + 1;
                res = max(res, curmax);
                m[n] = 0;   /* 这行代码非常必要，它使得重复出现的元素不会累积 */
                m[n-left] = curmax;
                m[n+right] = curmax;
            }
        }

        return res;
    }
};
