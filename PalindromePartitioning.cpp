#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool ispalin(string &s, int i, int j) {
        for (; i<=j; i++, j--) {
            if (s[i] != s[j]) return false;
        }

        return true;
    }

    void search(vector<string> &curres, string &str, size_t cur, vector< vector<string> > &res) {
        size_t sz = str.size();
        if (cur == sz) {
            res.push_back(curres);
            return;
        }

        for (size_t i=cur; i<sz; i++) {
            if (ispalin(str, cur, i)) {
                curres.push_back(str.substr(cur, i-cur+1));
                search(curres, str, i+1, res);
                curres.pop_back();
            }
        } 
    }

    vector< vector<string> > partition(string s) {
        vector<vector<string>> res;
        vector<string> curres;

        search(curres, s, 0, res);

        return res;
    }
};

int main() {
    Solution s;
    vector< vector<string> > res(s.partition("a"));

    cout << res.size() << endl;
    return 0;
}
