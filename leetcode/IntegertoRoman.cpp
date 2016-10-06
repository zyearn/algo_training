class Solution {
public:
    string intToRoman(int num) {
        string int_to_roman[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"},
        };
        
        string result;
        int index = 0;
        while (num) {
            int rem = num % 10;
            result = int_to_roman[index][rem] + result;

            num /= 10;
            index++;
        }

        return result;
    }
};
