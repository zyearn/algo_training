class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> m;
        for (int i=0; i<A.size(); i++) {
            for (int j=0; j<B.size(); j++) {
                int s = A[i] + B[j];
                m[s]++;
            }
        }

        int res = 0;
        for (int i=0; i<C.size(); i++) {
            for (int j=0; j<D.size(); j++) {
                int s = C[i] + D[j];
                res += m[-s];
            }
        }

        return res;
    }
};
