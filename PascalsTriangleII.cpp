class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vCur;

        if (numRows < 0) {
            return vCur;
        }
        
        vCur.push_back(1);

        while (rowIndex-- > 0) {
            vector<int> vTmp;
            vTmp.push_back(1);

            for (int i=1; i<vCur.size(); i++) {
                vTmp.push_back(vCur[i-1] + vCur[i]);
            }

            vTmp.push_back(1);
            vCur = vTmp;
        }

        return vCur;
    }
};
