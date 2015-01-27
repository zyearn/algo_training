/*
 * 当计算f(n)时，有如下n种情况：
 *      当1为根时，有剩下的全部在1的右节点上，所以还有f(n-1)种情况
 *      当2为根时，左节点只能是1，所以是f(1)，右边是f(n-2)，所以有f(1)*f(n-2)种情况
 *      ...
 *      当n为根时，剩下的全部都在左节点上，所以有f(n-1)种情况
 *
 *  综上，定义f(0) =1, f(n) = f(0)f(n-1) + f(1)f(n-2) + ... + f(n-2)f(1) + f(n-1)f(0);
 * 这个数有另外一个名字叫 Catalan number
 */

#include <iostream>
using namespace std;

class Solution {
    public:
    int numTrees(int n) {
        int *f = new int[n+1];        
        f[0] = f[1] = 1;

        for (int i=2; i<=n; ++i){
            f[i] = 0;
            for (int j=0; j<i; j++){
                f[i] += (f[j] * f[i-1-j]);
            }

        }
        int ans = f[n];
        delete[] f;
        return ans; 
    }
};

int 
main(void){
    Solution sol;

    for(int i=1; i<6; ++i)
        cout << sol.numTrees(i) << endl;

    return 0;
}
