#include <map>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> res;
    int n;
    int m;

public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return;

        n = matrix.size();
        m = matrix[0].size();
        res = vector<vector<int>>(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                res[i][j] = res[i-1][j] + res[i][j-1] - res[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return res[row2+1][col2+1] - res[row2+1][col1] - res[row1][col2+1] + res[row1][col1];
    }
};

int main() {
    vector<vector<int>> m{
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix numMatrix(m);

    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
    cout << numMatrix.sumRegion(1, 1, 2, 2) << endl;
    cout << numMatrix.sumRegion(1, 2, 2, 4) << endl;

    /*
    vector<vector<int>> m{
        {1,2},
        {3,4}
    };
    NumMatrix numMatrix(m);

    cout << numMatrix.sumRegion(0, 0, 0, 0) << endl;
    cout << numMatrix.sumRegion(0, 0, 0, 1) << endl;
    cout << numMatrix.sumRegion(0, 0, 1, 1) << endl;
    */

    
    return 0;
}
// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
