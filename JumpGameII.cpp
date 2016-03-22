class Solution {
public:
    int max(int a, int b) {
        return (a>b)?a:b;
    }

    int jump(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0 || sz == 1) return 0;

        int gmax = nums[0];
        int curmax = nums[0];
        int step = 1;

        for (int i=1; i<sz; i++) {
            curmax = max(curmax, nums[i] + i);

            if (i == sz-1) {
                return step;
            }

            if (i == gmax) {
                gmax = curmax;
                step++;
            }
        }
    }
};
