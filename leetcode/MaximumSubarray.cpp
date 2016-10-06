/*
 * DP问题
 * 设Max是以A[n]为结尾子串的最大值
 * 那么下一个以A[n+1]为结果的最大值为MAX(Max + A[n+1], A[n+1]) (当Max>0时，取前者，否则取后者)
 */
class Solution {
    public:

    int MAX2(int a, int b){
        return (a > b) ? a:b;
    }

    int maxSubArray(int A[], int n) {
        int Max, curMax;
        Max = curMax = A[0];

        for (int i=1; i<n; i++){
            int tmp = Max + A[i];
            Max = MAX2(tmp, A[i]);
            curMax = (Max > curMax) ? Max:curMax;
        }
        return curMax;
    }
};
