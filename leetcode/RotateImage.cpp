class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        _rotate(matrix, 0, n);
    }

    void _rotate(vector<vector<int>>& matrix, int index, int n) {
        int end = n-1-index;

        if (index >= end)
            return;

        int i, j;
        int tmp;
        for (int _i=index; _i<end; _i++) {
            i = index;
            j = _i;

            tmp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = tmp;
            
        }
        
        _rotate(matrix, index+1, n);
    }
};
