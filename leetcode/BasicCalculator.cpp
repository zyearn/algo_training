#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> ops, nums;
        int sign = 1;
        int res = 0;
        int number = 0;
        char c;

        for (size_t i=0; i<s.size(); i++) {
            c = s[i];

            if (isdigit(c)) {
                number = number*10 + c - '0';
            } else if (c == '+') {
                res += (sign * number);
                sign = 1;
                number = 0;
            } else if (c == '-') {
                res += (sign * number);
                sign = -1;
                number = 0;
            } else if (c == '(') {
                ops.push(sign);
                nums.push(res);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += (sign * number);
                res = nums.top() + ops.top() * res;
                nums.pop();
                ops.pop();
                number = 0;
            } else {
                continue;
            }
        }

        res += sign * number; 
        return res;
    }
};

int main() {
    string s("(1+(4+5+2)-3)+(6+8)");

    Solution st;
    cout << st.calculate(s);


    return 0;
}
