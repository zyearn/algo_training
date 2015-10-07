class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rSize = matrix.size();
        int cSize = matrix[0].size();

        if (rSize < 1 || cSize < 1) return false;
        int row = 0, col = cSize - 1;

        while (row < rSize && col >= 0) {
            if (target < matrix[row][col]) {
                col--;
            } else if (target > matrix[row][col]) {
                row++;
            } else {
                return true;
            }
        }

        return false;
    }
};
