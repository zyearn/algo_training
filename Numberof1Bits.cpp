class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i=0; i<8; i++) {
            res += (n & 0x01010101);
            n >>= 1;
        }

        res = res + (res >> 16);
        res = res + (res >> 8);

        return res & 0xFF;
    }
};
