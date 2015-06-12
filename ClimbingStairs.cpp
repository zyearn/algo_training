class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 0) {
            return 1;
        }

        int *result = new int[n+1];
        result[0] = result[1] = 1;

        for (int i=2; i<n+1; i++) {
            result[i] = result[i-1] + result[i-2];
        }

        delete[] result;

        return result[n];
        
    }
};
