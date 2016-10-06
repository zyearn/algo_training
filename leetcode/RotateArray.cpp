/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        if (k == 0) return;

        int target = size - k;
        vector<int> res(size);
        
        int resIndex = 0;
        for (int i=target; i<size; i++) {
            res[resIndex++] = nums[i];
        }

        for (int i=0; i<target; i++) {
            res[resIndex++] = nums[i];
        }

        nums = res;
        return;
    }
};
*/

class Solution {
public:
    // 参考编程珠玑的翻手问题
    void rotate(vector<int> &nums, int k) {
        int size = nums.size();
        k %= size;
        if (k == 0) return;

        reverse(nums.begin(), nums.begin() + size - k);
        reverse(nums.begin() + size - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
