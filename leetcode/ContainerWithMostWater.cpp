class Solution {
public:
    int min(int a, int b) {
        return (a<b)? a: b;
    }

    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int max = 0;
        int curmax, h;

        while (i < j) {
            h = min(height[i], height[j]);
            curmax = (j - i) * h;
            if (curmax > max) max = curmax;
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }

        return max;
    }
};
