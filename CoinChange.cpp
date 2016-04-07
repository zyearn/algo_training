class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount+1, ~(1<<31));
        vector<int> marked(amount+1, 0);

        size_t sz = coins.size();
        for (int i=0; i<sz; i++) {
            if (coins[i] <= amount) {
                res[coins[i]] = 1;
                marked[coins[i]] = 1;
            }
        }
        res[0] = 0;
        marked[0] = 1;

        for (int i=1; i<=amount; i++) {
            for (int j=0; j<sz; j++) {
                if (i >= coins[j] && marked[i-coins[j]]) {
                    res[i] = min(res[i], res[i-coins[j]]+1);
                    marked[i] = 1;
                }
            }
        }

        return (marked[amount] == 1)? res[amount]: -1;
    }
};
