#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
    * DP
    *   ans[n][m] = triangle[n][m] + min(ans[n+1][m], ans[n+1][m+1])
    */
    int min(int a, int b) {
        return (a<b)?a:b;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int nlen = triangle.size();
        if (nlen == 0) {
            return 0;
        }
        
        vector<int> curMin;
        for (int i=0; i<nlen+1; i++) {
            curMin.push_back(0);
        }

        for (int i=nlen-1; i>=0; i--) {
            vector<int> &cur = triangle[i];
            int curLen = cur.size();
            for (int j=0; j<curLen; j++) {
                curMin[j] = cur[j] + min(curMin[j], curMin[j+1]);
            }
        }

        return curMin[0];
    }
};

int main() {
    vector<vector<int>> t;
    t.push_back(vector<int>{2});
    t.push_back(vector<int>{3,4});
    t.push_back(vector<int>{6,5,7});
    t.push_back(vector<int>{4,1,8,3});

    Solution s;
    cout << s.minimumTotal(t) << endl;
    
    return 0;
}
