#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;

        int cols = matrix[0].size();
        vector<vector<int> > ans(rows, vector<int>(cols, 0));

        int sum = 0;
        int curmax = 0;
        for (int i=0; i<rows; i++) {
            ans[i][0] = matrix[i][0]- '0';
            sum += ans[i][0];
        }

        for (int i=0; i<cols; i++) {
            ans[0][i] = matrix[0][i] - '0';
            sum += ans[0][i];
        }

        if (sum != 0) curmax = 1;

        int side;
        for (int i=1; i<rows; i++) {
            for (int j=1; j<cols; j++) {
                side = ans[i-1][j-1];
                
                bool is = true;
                ans[i][j] = matrix[i][j] - '0';
                if (ans[i][j] == 1) {
                    for (int k=0; k<=side; k++) {
                       if (matrix[i-k][j] != '1' || matrix[i][j-k] != '1')  {
                           is = false;
                           break;
                       }
                    }

                    if (is) {
                        ans[i][j] = ans[i-1][j-1] + 1;
                        if (ans[i][j] > curmax) {
                            curmax = ans[i][j];
                        }
                    }
                }
            }
        }

        return curmax * curmax;
        
    }
};

int main() {
    vector<vector<char> > matrix{
        vector<char>{'1', '0', '1', '0', '0'},
        vector<char>{'1', '0', '1', '1', '1'},
        vector<char>{'1', '1', '1', '1', '1'},
        vector<char>{'1', '0', '0', '1', '0'},
    };

    Solution s;
    cout << s.maximalSquare(matrix);
    return 0;
}
