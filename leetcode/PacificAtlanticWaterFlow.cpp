#include <map>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int n, m;
    inline bool isOk(int ni, int nj) {
        return (ni >= 0) && (ni < n) && (nj >= 0) && (nj < m);
    }

    void dfs(int i, int j, vector<vector<int>> &v, vector<vector<int>>& matrix) {
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        v[i][j] = 1;
        for (int k=0; k<4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (!isOk(ni, nj)) {
                continue;
            }

            if (matrix[ni][nj] >= matrix[i][j] && !v[ni][nj]) {
                dfs(ni, nj, v, matrix);
            }
        }

    }

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = n? matrix[0].size(): 0;

        vector<pair<int, int>> res;
        vector<vector<int>> vis1(n, vector<int>(m, 0));
        vector<vector<int>> vis2(n, vector<int>(m, 0));

        for (int i=0; i<n; i++) {
            dfs(i, 0, vis1, matrix);
            dfs(i, m-1, vis2, matrix);
        }

        for (int i=0; i<m; i++) {
            dfs(0, i, vis1, matrix);
            dfs(n-1, i, vis2, matrix);
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (vis1[i][j] && vis2[i][j]) {
                    res.push_back(pair<int, int>(i, j));
                }
            }
        }

        return res;
    }
};
int main() {
    return 0;
}
