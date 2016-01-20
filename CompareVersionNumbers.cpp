#include <iostream>
using namespace std;

class Solution {
public:
    int getnumber(string s, string::size_type& sz) {
        if (sz >= s.size()) {
            return 0;
        }

        string::size_type size;
        int ret = std::stoi(s.substr(sz), &size);
        sz += size;
        return ret;
    }

    int compareVersion(string version1, string version2) {
        string::size_type sz1 = -1 , sz2 = -1;
        int v1, v2; 

        do {
            sz1++;
            sz2++;

            v1 = getnumber(version1, sz1);
            v2 = getnumber(version2, sz2);

            if (v1 < v2) return -1;
            if (v1 > v2) return 1; 
            
            if (sz1 >= version1.size() && sz2 >= version2.size())
                return 0;

        } while(1);
    }
};

int main() {
    Solution s;
    s.compareVersion("1.0", "1");

    return 0;
}
