#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int c = 1;
        int i = 0, j = 0;

        for (int k=0; k<(n+1)/2; k++) {
            res[i][j] = c++;

            while (j+1 < n && res[i][j+1] == 0) {
                j++;
                res[i][j] = c++;
            }

            while (i+1 <n && res[i+1][j] == 0) {
                i++;
                res[i][j] = c++;
            }

            while (j-1>=0 && res[i][j-1] == 0) {
                j -= 1;
                res[i][j] = c++;
            }

            while (i-1 >=0 && res[i-1][j] == 0) {
                i -= 1;
                res[i][j] = c++;
            }
            
            j += 1;
        }

        return res;
    }
};

int main() {
    Solution s;
    s.generateMatrix(3);

    return 0;
}
