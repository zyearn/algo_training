/*
 * good answer: https://leetcode.com/discuss/23901/my-short-solution-by-c-o-n2
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, bool> m;

        // check row
        size_t sRow = board.size();
        if (sRow != 9) return false;

        for (size_t i=0; i<9; i++) {
            m.clear();

            for (size_t j=0; j<9; j++) {
                if (m[board[i][j]] && board[i][j] != '.') {
                    return false;
                }

                m[board[i][j]] = true;
            }
        }

        // check column
        size_t sCol = board[0].size();
        if (sRow != 9) return false;

        for (size_t j=0; j<9; j++) {
            m.clear();

            for (size_t i=0; i<9; i++) {
                if (m[board[i][j]] && board[i][j] != '.') {
                    return false;
                }

                m[board[i][j]] = true;
            }
        }
        
        // check square
        size_t i_, j_;
        for (size_t i=0; i<3; i++) for (size_t j=0; j<3; j++) {
            m.clear();

            i_ = i * 3;
            j_ = j * 3;

            for (size_t k = i_; k<i_+3; k++) for (size_t q = j_; q<j_+3; q++) {
                if (m[board[k][q]] && board[k][q] != '.') {
                    return false;
                }

                m[board[k][q]] = true;
            }
        }

        return true;
    }
};
