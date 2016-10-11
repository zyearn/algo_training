#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = words.size();
        vector<int> bits(size);
        int res = 0;

        for (int i=0; i<size; i++) {
            int mask = 0;
            for (int j=0; j<words[i].size(); j++) {
                mask |= 1 << (words[i][j] - 'a');
            }
            bits[i] = mask; 

            for (int j=0; j<i; j++) {
                if (!(bits[i] & bits[j])) res = max(res, int(words[i].size()) * int(words[j].size()));
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<string> v{"abcw","baz","foo","bar","xtfn","abcdef"};

    cout << s.maxProduct(v) << endl;
}
