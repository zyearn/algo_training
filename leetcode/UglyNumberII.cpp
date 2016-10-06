class Solution {
public:
    int min(int a, int b) {
        return (a < b)? a: b;
    }

    int nthUglyNumber(int n) {
        if (n <= 1) return 1;
        
        vector<int> ugn(n);
        ugn[0] = 1;
        int t1 = 0, t2 = 0, t3 = 0;
        
        int curmin;
        for (int i=1; i<n; i++) {
            ugn[i] = min(ugn[t1]*2, min(ugn[t2]*3, ugn[t3]*5));
            if (ugn[i] == ugn[t1]*2) t1++;
            if (ugn[i] == ugn[t2]*3) t2++;
            if (ugn[i] == ugn[t3]*5) t3++;
        }

        return ugn[n-1];
    }
};
