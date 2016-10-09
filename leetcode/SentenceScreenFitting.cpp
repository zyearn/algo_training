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

/*

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int currow = 0;
        int remains = cols;
        int term = 0;
        int index = 0;
        int size = sentence.size();
         
        while (currow < rows) {
            int need = sentence[index % size].size();
            
            while (remains < need && currow < rows) {
                currow++;
                remains = cols;
            }

            if (currow == rows) break;

            remains -= need;
            if (remains > 0) remains--;
            index++;

            if (index % size == 0) {
                term++;
            }
        }
        
        return term;
    }
};

int main() {
    vector<string> s{"I", "had", "apple", "pie"};
    Solution so;
    cout << so.wordsTyping(s, 4, 5) << endl;
}
*/
