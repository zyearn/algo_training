class Solution {
public:
    int C(int m, int n) {
        // calculate mCn
        n = (m-n < n) ? n:(m-n);

        // use long long in case of overflow
        long long sum = 1;
        for (int i=0, _m=m; i<m-n; _m--, i++) {
            sum *= _m;
        }

        for (int _n=m-n; _n>1; _n--) {
            sum /= _n;
        }

        return sum;
    }

    int uniquePaths(int m, int n) {
        return C(m+n-2, m-1);
    }
};
