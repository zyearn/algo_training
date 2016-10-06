class Solution {
public:
#define BITS 32
    int missingNumber(vector<int>& nums) {
        int size = nums.size() + 1;
        int n = (size + BITS - 1) / BITS;
        int *bmap = (int *)malloc(n * sizeof(int));
        memset(bmap, 0, n * sizeof(int));

        for (int i=0; i<size-1; i++) {
            bmap[nums[i]/BITS] |= 1 << (nums[i]%BITS);
        }

        for (int i=0; i<size; i++) {
            if (!(bmap[i/BITS] & (1 << i%BITS))) {
                free(bmap);
                return i;
            }
        }
    }
};
