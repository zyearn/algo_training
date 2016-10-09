#include <map>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;


class Solution {
public:
    void add(char n, char m, int &carry, string &res) {
        int a = n - '0';
        int b = m - '0';
        int sum = a + b + carry;
        carry = (sum >= 10)?1:0;
        sum = sum % 10;
        res.push_back(sum + '0');
        return;
    }

    string addStrings(string num1, string num2) {
        string res("");

        size_t s1 = num1.size();
        size_t s2 = num2.size();
        int a, b;
        int c = 0;
        int sum = 0;
        int i,j;

        for (i=s1-1,j=s2-1; i>=0 && j>=0; i--, j--) {
            add(num1[i], num2[j], c, res);
        }

        while (i >= 0) {
            add(num1[i--], '0', c, res);
        }

        while (j >= 0) {
            add(num2[j--], '0', c, res);
        }

        if (c) {
            res.push_back('1');
        }

        for (i=0, j=res.size()-1; i<j; i++, j--) {
            int tmp = res[i];
            res[i] = res[j];
            res[j] = tmp;
        }

        return res;
    }
};

int main() {
    Solution s;
    string a("1212");
    string b("12");
    cout << s.addStrings(a, b) << endl;

    return 0;
}
