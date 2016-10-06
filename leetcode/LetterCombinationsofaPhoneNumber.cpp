class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static map<char, vector<char>> m{
            {'2', vector<char>{'a', 'b', 'c'}},
            {'3', vector<char>{'d', 'e', 'f'}},
            {'4', vector<char>{'g', 'h', 'i'}},
            {'5', vector<char>{'j', 'k', 'l'}},
            {'6', vector<char>{'m', 'n', 'o'}},
            {'7', vector<char>{'p', 'q', 'r', 's'}},
            {'8', vector<char>{'t', 'u', 'v'}},
            {'9', vector<char>{'w', 'x', 'y', 'z'}}
        };
    
        int len = digits.size();
        vector<string> res;

        if (len != 0) h_(m, digits, 0, len, "",res);

        return res;
    }

    void h_(map<char, vector<char>> &m, string &digits, int start, int len, string curstr, vector<string> &res) {
        if (start == len) {
            res.push_back(curstr);
            return;
        }

        vector<char> &vc = m[digits[start]];
        for (int i=0; i<vc.size(); i++) {
            h_(m, digits, start+1, len, curstr + vc[i], res);
        }
    
        return;
    }
};
