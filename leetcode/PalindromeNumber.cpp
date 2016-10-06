class Solution {
public:
    bool isPalindrome(int x) {
        if (x >= 0 && x <= 9) {
            return true;
        }

        if (x < 0 || x % 10 == 0) {
            return false;
        }

        int palind = 0;

        while (x > palind) {
            palind = palind * 10 + x % 10;
            x /= 10;
        }

        return (x == palind || x == palind/10);
    }
};
