/*
#include <vector>
#include <iostream>
using namespace std;
*/

class Solution {
public:
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void _permute(vector<int>& nums, int low, vector<vector<int>>& vvResult) {
        int size = nums.size();
        if (low >= size) {
            vvResult.push_back(nums);
            return;
        }

        for (int i=low; i<size; i++) {
            swap(nums[low], nums[i]);
            _permute(nums, low+1, vvResult);
            swap(nums[low], nums[i]);
        }    

        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vvResult;
        _permute(nums, 0, vvResult);

        return vvResult;
    }
};

/*
int main() {
    Solution s;
    
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> vvR = s.permute(nums);
    cout << "sizeof result = " << vvR.size() << endl;

    for (int i=0; i<vvR.size(); i++) {
        cout << "result " << i << endl;
        vector<int>& vR = vvR[i];
        for (int j=0; j<vR.size(); j++) {
            cout << vR[j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
*/
