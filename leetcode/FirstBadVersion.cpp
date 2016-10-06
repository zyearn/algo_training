// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int h = n;
        int mid;

        while (l < h) {
            mid = l + (h - l) /2;
            if (isBadVersion(mid)) h = mid;
            else l = mid + 1;
        }

        return l;
    }
};
