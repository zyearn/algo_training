class Solution {
public:
    int _sum(vector<int>& v) {
        size_t s = v.size();
        int sum = 0;

        for (int i=0; i<s; i++) {
            sum += v[i];
        }

        return sum;
    }
    
    void _h(int k, int n, int next, vector<int>& curres, vector<vector<int>>& res) {
        if (curres.size() == k) {
            if (_sum(curres) == n) {
                res.push_back(curres);
            }
            return;
        }

        for (int i=next; i<10; i++) {
            if (_sum(curres) + i <= n) {
                curres.push_back(i);
                _h(k, n, i+1, curres, res);
                curres.pop_back();
            } else {
                break;
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curres;

        _h(k, n, 1, curres, res);
        return res;
    }
};
