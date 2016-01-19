class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, 0);
        ans[0] = 1;

        for (int i=1; i<len; i++) {
            for (int j=i-1; j>=0; j--) {
                if (ans[j] && nums[j] >= i-j) {
                    ans[i] = 1;
                    break;
                }
            } 
        }
        
        return ans[len-1]?true: false;
    }
};
