/*
#include <vector>
#include <stdio.h>
using namespace std;
*/

class Solution {
public:
    /*
        返回ret，满足v[ret]是小于等于target的数中最大的数
    */
    int binarySearch(vector<int>& v, int target) {
        int low = 0;
        int high = v.size() - 1;
        int mid;

        while (low < high) {
            mid = low + (high-low+1)/2;
            if (target < v[mid]) {
                high = mid - 1; 
                continue;
            } else if (target > v[mid]) {
                low = mid;
                continue;
            }

            return mid;
        }

        return low;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> vFirst;
        int size = matrix.size();

        for (int i=0; i<size; i++) {
            vFirst.push_back(matrix[i][0]);
        }

        int ret = binarySearch(vFirst, target);
        vector<int> &vRow = matrix[ret];

        ret = binarySearch(vRow, target);
        if (vRow[ret] == target) {
            return true;
        }

        return false;
    }
};

/*
int main() {
    vector<int> v = {0, 2, 4, 6, 11, 20, 24};
    Solution s;
    int ret;
    
    ret = s.binarySearch(v, 2);
    printf("ret = %d, expect %d", ret, 1);

    ret = s.binarySearch(v, 3);
    printf("ret = %d, expect %d", ret, 1);

    ret = s.binarySearch(v, 15);
    printf("ret = %d, expect %d", ret, 4);

    ret = s.binarySearch(v, 23);
    printf("ret = %d, expect %d", ret, 5);

    return 0;
}
*/
