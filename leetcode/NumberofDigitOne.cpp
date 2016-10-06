class Solution {
public:
    int countDigitOne(int n) {
        long long pre, post;

        for (long long k=1; k <= n; k *= 10) {
            pre = n/k;
            post = n%k;

            int msb = pre % 10;

            if (msb > 1) {
                sum += (pre/10 + 1) * k;
            } else if (msb == 1) {
                sum += (pre/10 * k + post + 1);
            } else {
                sum += (pre/10 * k);
            }
        }

        return sum;
    }
};
