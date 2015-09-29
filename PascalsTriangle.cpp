class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        if (numRows <= 0) {
            return res;
        }
        
        res.push_back(vector<int>());
        res[0].push_back(1);
        numRows--;

        while (numRows-- > 0) {
            vector<int> &last = res[res.size() - 1];
            vector<int> newRow;
            newRow.push_back(1);

            for (int i=1; i<last.size(); i++) {
                newRow.push_back(last[i-1] + last[i]);
            }

            newRow.push_back(1);
            res.push_back(newRow);
        }

        return res;
    }
};
