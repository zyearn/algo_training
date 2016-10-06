class NumArray {
public:
    vector<int> res;

    NumArray(vector<int> &nums):
        res(nums.size() + 1) {
        res[0] = 0;

        for (int i=0; i<nums.size(); i++) {
            res[i+1] = res[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
       return res[j+1] - res[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
