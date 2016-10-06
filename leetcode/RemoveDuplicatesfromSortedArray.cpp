#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (!len) {
            return 0;
        }

        int last = 0;

        for (int i=0; i<len; i++) {
            if (nums[i] != nums[last]) {
                nums[++last] = nums[i];
            }
        }

        return last+1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    int len = s.removeDuplicates(nums);

    cout << "len = " << len << endl;

    for (int i=0; i<nums.size(); i++) {
        cout << nums[i] << endl;
    }

    return 0;
}
