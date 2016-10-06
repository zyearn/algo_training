class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";

        if (b.size() > a.size()) {
            string tmp = a;
            a = b;
            b = tmp;
        }

        int carry = 0;
        int tmpSum = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        for (; j >= 0; i--, j--) {
            tmpSum = a[i] - '0' + b[j] - '0' + carry;
            ans = char(tmpSum % 2 + '0') + ans;
            if (tmpSum >= 2) carry = 1;
            else carry = 0;
        }

        if (!carry) {
            return a.substr(0, i+1) + ans;
        }

        for (; i >= 0; i--) {
            if (a[i] == '0') {
                ans = '1' + ans;
                return a.substr(0, i) + ans;
            } else {
                ans = '0' + ans;
            }
        }

        ans = '1' + ans;
        return a;
    }
};
