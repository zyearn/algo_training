class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int len = citations.size();
        int i = 0;
        for (; i<len; i++) {
            if (citations[i] >= len-i) {
                break;
            }
        }

        return (len - i);
    }
};
