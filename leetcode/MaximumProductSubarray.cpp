/*
 * DP问题
 * 设Max，Min是以A[n]为结尾的最大值，最小值；curMax是当前计算的Max中最大的那个
 * 
 * 这题不仅要记录最大值，还要记录最小值的原因是最小值可能乘以一个负数就变成了最大值。
 *
 */
class Solution {
    public:
    int MAX3(int a, int b, int c){
        int tmp = (a > b) ? a:b;
        tmp = (tmp > c) ? tmp: c;
        return tmp;
    }

    int MIN3(int a, int b, int c){
        int tmp = (a < b) ? a:b;
        tmp = (tmp < c) ? tmp: c;
        return tmp;
    }
    
    int maxProduct(int A[], int n) {
        int Max, Min;
        int curMax;
        Max = Min = curMax = A[0];

        for (int i=1; i<n; ++i){
            int tmpMax = Max * A[i];
            int tmpMin = Min * A[i];
            Max = MAX3(tmpMax, tmpMin, A[i]);
            Min = MIN3(tmpMax, tmpMin, A[i]);

            curMax = (Max > curMax) ? Max : curMax; 
        }
        return curMax;
    }
};
