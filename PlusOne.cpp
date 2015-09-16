class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int size = digits.size();
        int sum = 0;

        for (int i=size-1; i>=0; i--) {
            sum = digits[i] + carry;
            carry = sum / 10;
            digits[i] = sum % 10;

            if (carry == 0) {
                break;
            }
        }

        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
