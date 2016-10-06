/*
这题比较trick的地方在于 输入nums并不是在所有情况下都是rotated的，要处理一些没有rotate的情况，
对应while里的第一个if
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        vector<int> numsFilter;
        int last = nums[0];
        numsFilter.push_back(nums[0]);

        for (int i=1; i<nums.size(); i++) {
            if (nums[i] != last) {
                numsFilter.push_back(nums[i]);
            }

            last = nums[i];
        }

        nums = numsFilter;

        int low = 0, high = nums.size()-1;
        int middle;

        while (low < high) {
            if (nums[low] < nums[high]) {
                return nums[low];
            }

            middle = (low + high) / 2;
            if (nums[middle] > nums[high]) {
                low = middle + 1;
            } else {
                high = middle;
            }
        }

        return nums[low];
    }
};
