class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, h = numbers.size() - 1;
        vector<int> res;

        while (l <= h) {
            int sum = numbers[l] + numbers[h];
            if (sum == target) {
                res.push_back(l+1);
                res.push_back(h+1);
                break;
            }

            if (sum < target) {
                l+=1;
            } else {
                h-=1;
            }
        }

        return res;
    }
};
