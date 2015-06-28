class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        int curMin = prices[0];
        int result = 0;

        for (int i=1; i<prices.size(); i++) {
            if (prices[i] < curMin) {
                curMin = prices[i];
                continue;
            }

            if (prices[i] - curMin > result) {
                result = prices[i] - curMin;
            }
        }

        return result;
    }
};
