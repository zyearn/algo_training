class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for (int sft = 0; sft < 32; sft++) {
            if (n & (1 << sft)) {
                res |= (1 << (31 - sft));
            }
        }
        
        return res;
    }
};
