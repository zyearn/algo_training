#include <iostream>
#include <vector>
using namespace std;

/**
* DP 
* if obstacleGrid[i][j] == 1: ans[i][j] = 0;
* if obstacleGrid[i][j] == 0: ans[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j]
* 有三个for是因为前两个for在处理第一行和第一列
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;

        obstacleGrid[0][0] = 1 - obstacleGrid[0][0]; 

        for (int i=1; i<n; i++) {
            if (obstacleGrid[0][i] == 1) {
                obstacleGrid[0][i] = 0;
            } else {
                obstacleGrid[0][i] = obstacleGrid[0][i-1];
            }
        }

        for (int i=1; i<m; i++) {
            if (obstacleGrid[i][0] == 1) {
                obstacleGrid[i][0] = 0;
            } else {
                obstacleGrid[i][0] = obstacleGrid[i-1][0];
            }
        }

        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                } else {
                    obstacleGrid[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j];
                }
            }
        }

        return obstacleGrid[m-1][n-1];
        
    }
};

int main() {
    vector<vector<int>> t;
    t.push_back(vector<int>{1});
    t.push_back(vector<int>{0});

    Solution s;
    cout << s.uniquePathsWithObstacles(t) << endl;

    return 0;
}
