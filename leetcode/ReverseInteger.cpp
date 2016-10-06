class Solution {
public:
    int reverse(int x) {
        int sign = x>=0 ? 1 : -1;
        x *= sign;
        
        char num[20];
        sprintf(num, "%d", x);
        
        int len = strlen(num) - 1;
        for (int i=0, j=len; i<j; i++, j--)
        {
            char tmp = num[i];
            num[i] = num[j];
            num[j] = tmp;
        }
        
        return atoi(num) * sign;
    }
};
