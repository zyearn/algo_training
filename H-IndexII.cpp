class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 0, high = citations.size()-1;
        int len = citations.size();
        int lowwest = INT_MAX;
        int mid;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (citations[mid] >= len - mid) {
                if (mid < lowwest) {
                    lowwest = mid;
                }
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (lowwest != INT_MAX) {
            return len - lowwest;
        }

        return 0;
     }
};
