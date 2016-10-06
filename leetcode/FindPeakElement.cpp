class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;
        int m1, m2;
        
        while (l < h) {
            m1 = l + (h-l)/2;
            m2 = m1 + 1;

            if (nums[m1] > nums[m2]) {
                h = m1;
            } else {
                l = m2;
            }
        }

        return l;
    }
};
