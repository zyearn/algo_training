/*
动态规划，关键是找到最优子问题以及转移方程。
设result[n]是以s[n]为结尾的子串的解，写出转移方程：
result[n] = (result[n-1] && s[n]...s[n] is in dict) || (result[n-2] && s[n-1]...s[n] is in dict) || ... || (result[0] && s[1]...s[n] is in dict) || (s[0]...s[n] is in dict)

*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s  == "")
            return (dict.find(s) != dict.end());

        bool result[s.length()];
        result[0] = (dict.find(s.substr(0,1)) != dict.end());

        for (size_t i=1; i<s.length(); ++i) {
            if (dict.find(s.substr(0, i+1)) != dict.end()) {
                result[i] = true;
                continue;
            } 

            result[i] = false;
            for (size_t j=i; j>0; j--) {
                if (result[j-1] && (dict.find(s.substr(j, i-j+1)) != dict.end()) ) {
                    result[i] = true;
                    break;
                }
            }
        }

        return result[s.length() - 1];
    }
};
