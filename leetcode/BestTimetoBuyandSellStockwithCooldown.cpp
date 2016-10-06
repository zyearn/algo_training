#include <vector>
using namespace std;

/**
 *
 * 以res[n]为以prices[0]...prices[n]为输入时的maxprofift
 * prices[n]要么不被卖掉，要么被卖掉，所以转移方程：
 * res[n] = max{res[n-1], max{prices[n] - prices[i] + res[i-2] for 0<=i<n } }
 *
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> res(prices.size());
        if (prices.size() == 0) return 0;
        int cur_prof = 0;

        for (int i=0; i<res.size(); i++) {
            res[i] = 0;

            for (int j=i-1; j>=0; j--) {
                cur_prof = 0;
                if (prices[i] > prices[j]) {
                    cur_prof += (prices[i] - prices[j]);
                }

                if (j-2 >= 0) {
                    cur_prof += res[j-2];
                }

                res[i] = (cur_prof > res[i])? cur_prof: res[i];
            }   

            if (i > 0) res[i] = (res[i-1] > res[i])? res[i-1]: res[i];
        }

        return res[res.size() - 1];
    }
};
