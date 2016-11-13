#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class Solution {
public:
    inline bool isEqual(string &o, int i, string &t, int size) {
        for (int j=0; j<size; j++) {
            if (o[i+j] != t[j]) {
                return false;
            }
        }

        return true;
    }

    bool repeatedSubstringPattern(string str) {
        int size = str.size();

        for (int i=1; i<size; i++) {
            if ((size % i) != 0) continue;

            int times = size / i;
            string rep = str.substr(0, i);

            int t;
            for (t=0; t<size; t+=i) {
                if (!isEqual(str, t, rep, i)) {
                    break;
                }
            }

            if (t == size) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    Solution s;
    cout << s.repeatedSubstringPattern("abcabcabcabc") << endl;

}
