class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        size_t gs = g.size();
        size_t ss = s.size();
        int gi = 0, si = 0;

        int ans = 0;
        while (gi < gs && si < ss) {
            if (s[si] >= g[gi]) {
                ans++;
                gi++;
            }

            si++;
        }

        return ans;
    }
};
