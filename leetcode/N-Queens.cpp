class Solution {
public:
    int abs(int a) {
        return (a<0)?-a:a;
    }

    bool conflict(vector<int>& rows, int k) {
        int curcol = rows.size();
        for (int i=0; i<curcol; i++) {
            if (rows[i] == k) {
                return true;
            }

            if (abs(curcol-i) == abs(rows[i]-k)) {
                return true;
            }
        }
        
        return false;
    }

    void dfs(int col, vector<int>& rows, int n, vector<vector<string>> &res) {
        if (col == n) {
            vector<string> r;
            vector<int> cols(rows.size());

            for (int i=0; i<rows.size(); i++) {
                cols[rows[i]] = i;
            }

            string tmp;
            for (int i=0; i<n; i++) {
                tmp.push_back('.');
            }

            for (int i=0; i<n; i++) {
                tmp[cols[i]] = 'Q';
                r.push_back(tmp);
                tmp[cols[i]] = '.';
            }

            res.push_back(r);
        }

        for (int i=0; i<n; i++) {
            if (conflict(rows, i)) {
                continue;
            }

            rows.push_back(i);
            dfs(col+1, rows, n, res);
            rows.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> rows;
        dfs(0, rows, n, res);

        return res;
    }
};
