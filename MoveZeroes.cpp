class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        int size = nums.size();
        int i = 0;
        
        for (; i<size; i++) {
            if (nums[i] != 0) {
                nums[cur] = nums[i];
                cur++;
            }
        }

        while (cur < size) {
            nums[cur] = 0;
            cur++;
        }
    }
};
