#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> n;
        n.insert(pair<char, int>('I', 1));
        n.insert(pair<char, int>('V', 5));
        n.insert(pair<char, int>('X', 10));
        n.insert(pair<char, int>('L', 50));
        n.insert(pair<char, int>('C', 100));
        n.insert(pair<char, int>('D', 500));
        n.insert(pair<char, int>('M', 1000));

        int res = 0;

        int size = s.size();
        for (int i=0; i<size; i++) {
            if (i+1 < size && n[s[i]] < n[s[i+1]]) {
                res += (n[s[i+1]] - n[s[i]]);
                i++;
            } else {
                res += (n[s[i]]);
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.romanToInt("M") << endl;
    return 0;

}
