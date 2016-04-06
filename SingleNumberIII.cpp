class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xors = 0;
        for (int num: nums) {
            xors ^= num;
        }
        xors &= -xors;

        vector<int> res(2, 0);
        for (int num: nums) {
            if (num & xors) {
                res[0] ^= num;
            } else {
                res[1] ^= num;
            }
        }

        return res;
    }
};
