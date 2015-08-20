class Solution {
public:
    bool isHappy(int n) {
        set<int> result;
        result.insert(n);

        while (n != 1) {
            int sum = 0;
            for (; n; n/=10) {
                sum += (n%10) * (n%10);
            }

            if (result.count(sum)) {
                return false;
            }

            result.insert(sum);
            n = sum;
        }

        return true;
    }
};
