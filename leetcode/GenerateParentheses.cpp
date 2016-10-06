class Solution {
public:
    void _h(string s, int x, int y, vector<string> &res) {
        if (x == 0 && y == 0) {
            res.push_back(s);
            return;
        }

        if (x > 0 && x-1 <= y) {
            _h(s + "(", x-1, y, res);
        }

        if (y > 0 && x <= y-1) {
            _h(s + ")", x, y-1, res);
        }
    }

    vector<string> generateParenthesis(int n) {
        string s("");
        vector<string> res;
        _h(s, n, n, res);

        return res;
    }
};
