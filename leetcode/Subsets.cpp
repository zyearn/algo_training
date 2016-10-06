class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        if (size <= 0) {
            return vector<vector<int>>();
        }
        
        int ssSize = 1 << size;
        vector<vector<int>> res(ssSize, vector<int>());
        sort(nums.begin(), nums.end());

        for (int i = 0; i < ssSize; i++) {
            for (int j = 0; j < size; j++) {
                if (i & (1 << j))
                    res[i].push_back(nums[j]);
            }
        }
        
        return res;
    }
};
