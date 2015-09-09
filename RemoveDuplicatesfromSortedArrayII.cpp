class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) {
            return len;
        }

        int last = 1;

        for (int i=2; i<len; i++) {
            if (nums[i] != nums[last-1]) {
                nums[++last] = nums[i];    
            }    
        }
        
        return last+1;
    }
};
