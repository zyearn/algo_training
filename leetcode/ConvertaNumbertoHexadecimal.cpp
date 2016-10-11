#include <iostream>
using namespace std;

class Solution {
public:
    char conv(int n) {
        if (n < 10) return '0' + n;
        else return 'a' + (n-10);
    }

    string toHex(int num) {
        string res(8, 0);

        for (int i=0; i<8; i++) {
            int c = (num >> (i*4)) & 0xf;
            res[7-i] = conv(c);
        }

        int i = 0;
        for (; i<res.size(); i++) {
            if (res[i] != '0') {
                break;
            }
        }

        string r = res.substr(i);
        return (r.size() == 0)? "0" : r;
    }
};

int main() {
    Solution s;
    cout << s.toHex(0) << endl;

    return 0;
}
