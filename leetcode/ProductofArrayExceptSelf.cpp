class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size);

        if (size == 0) {
            return res;
        }

        res[0] = 1;
        for (int i=1; i<size; i++) {
            res[i] = res[i-1] * nums[i-1];
        }

        int r = 1;
        for (int i=size-1; i>=0; i--) {
            res[i] *= r;
            r *= nums[i];
        }

        return res;
    }
};
