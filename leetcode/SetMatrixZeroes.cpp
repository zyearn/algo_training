class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int iRowSize = matrix.size();
        int iColSize = matrix[0].size();
        set<int>::iterator it;
        int iTheRow;
        int iTheCol;

        set<int> sRows, sCols;

        for (int i=0; i<iRowSize; i++) {
            for (int j=0; j<iColSize; j++) {
                if (matrix[i][j] == 0) {
                    sRows.insert(i);
                    sCols.insert(j);
                }
            }
        }

        for (it = sRows.begin(); it != sRows.end(); it++) {
            iTheRow = *it;
            for (int j=0; j<iColSize; j++) {
                matrix[iTheRow][j] = 0;
            }
        }

        for (it = sCols.begin(); it != sCols.end(); it++) {
            iTheCol = *it;
            for (int i=0; i<iRowSize; i++) {
                matrix[i][iTheCol] = 0;
            }
        }

        return;
    }
};
