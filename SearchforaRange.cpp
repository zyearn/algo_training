class Solution {
public:
    int lr(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (target <= nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (nums[low] == target)? low: -1;
    }

    int rr(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (target >= nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (nums[high] == target)? high: -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{lr(nums, target), rr(nums, target)} ;
        return res;
    }
};
