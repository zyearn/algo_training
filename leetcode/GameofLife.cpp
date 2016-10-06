class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = m? board[0].size(): 0;
        int count;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                count = 0;
                for (int ii=max(i-1, 0); ii<min(i+2, m); ii++) {
                    for (int jj=max(j-1, 0); jj<min(j+2, n); jj++) {
                        if (ii == i && jj == j) continue;
                        if (board[ii][jj] & 1) {
                            count++;
                        }
                    }
                }

                if ((board[i][j] & 1) == 1 && (count == 2 || count == 3)) {
                    board[i][j] |= 2;
                } 

                if ((board[i][j] & 1) == 0 && count == 3) {
                    board[i][j] |= 2;
                }
            }
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                board[i][j] >>= 1;
            }
        }

        return;
    }
};
