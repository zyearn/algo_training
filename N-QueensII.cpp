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

    void dfs(int col, vector<int>& rows, int n, int& sum) {
        if (col == n) {
            sum++;
            return;
        }

        for (int i=0; i<n; i++) {
            if (conflict(rows, i)) {
                continue;
            }

            rows.push_back(i);
            dfs(col+1, rows, n, sum);
            rows.pop_back();
        }
    }

    int totalNQueens(int n) {
        vector<int> rows;
        int sum = 0;
        dfs(0, rows, n, sum);

        return sum;
    }
};
