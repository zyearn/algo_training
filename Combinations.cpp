#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    void _combine(int start, int end, int k, vector<int> &nums, vector<vector<int>> &vvResult) {
        if (k <= 0) {
            vvResult.push_back(nums);
            return;
        }

        for (int i=start; i<=end-k+1; i++) {
            nums.push_back(i);
            _combine(i+1, end, k-1, nums, vvResult);
            nums.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0 || n < k) {
            return vector<vector<int>>();
        }

        vector<vector<int>> vvResult;
        vector<int> nums;

        _combine(1, n, k, nums, vvResult);

        return vvResult; 
    }
};

/**
* Solution two: reference https://leetcode.com/discuss/49388/c-solution-using-bit-operation-with-full-explanation
*/

/*
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> cur;
        
        for(int i = 0; i < 1<<n; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                int valid = (i>>j) & 1;
                sum += valid;
                if(valid) cur.push_back(j+1);
            }
            if(sum == k) result.push_back(cur);
            cur.clear();
        }
        return result;
    }
};
*/

void print_vector(const vector<int> &v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        cout << "argu";
        return -1;
    }

    Solution s;
    vector<vector<int>> vvR = s.combine(atoi(argv[1]), atoi(argv[2]));

    for (int i=0; i<vvR.size(); i++) {
        print_vector(vvR[i]);
    }

    cout << "size = " << vvR.size() << endl;

    return 0;
}
