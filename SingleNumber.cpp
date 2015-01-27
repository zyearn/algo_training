class Solution {
public:
    int singleNumber(int a[], int n) {
        if (n <= 0)
            return -1;

        for (int i=1; i < n; i++)
        {
            a[0] ^= a[i];
        }
        return a[0];
    }
};
