#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void _h(vector<int>& can, int target, vector<int>& curres, int curi, int cursum, vector<vector<int>>& res) {
        if (cursum == target) {
            res.push_back(curres);
            return;
        }

        size_t s = can.size();

        for (size_t i=curi; i<s; i++) {
            if (cursum + can[i] <= target) {
                curres.push_back(can[i]);
                _h(can, target, curres, i, cursum + can[i], res);
                curres.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        
        vector<int> curres;
        _h(candidates, target, curres, 0, 0, res);
        return res;
    }
};

void print_v(vector<int> &v) {
    for (size_t i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    Solution s;
    vector<int> c{2, 3, 6, 7};

    vector<vector<int>> res = s.combinationSum(c, 7);

    for (size_t i=0; i<res.size(); i++)
        print_v(res[i]);
    
    return 0;
}
