/*
动态规划，和word break类似。
这里的关键是要先用word break的方法来判断是否可以拆分，可以则继续往下做，若不先检查直接做，会MLE。
转移方程：
设res_vec[n]为以s[n]为结尾子串的解（是一个string的vector），那么res_vec[n] = res_vec[j]每个元素 和 s[j+1]...s[n] 的组合，j=0...n-1 并上 s[0]...s[n] 若s[0]...s[n]在dict中.
*/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        bool result[s.length()];

        for (size_t i=0; i<s.length(); ++i) {
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
        if (!result[s.length() - 1]){
            return vector<string>();
        }

        vector< vector<string> > res_vec(s.length());

        for (size_t i=0; i<s.length(); ++i) {
            if (dict.find(s.substr(0, i+1)) != dict.end()) {
                res_vec[i].push_back(s.substr(0, i+1));
            }

            for (size_t j=i; j>0; j--) {
                if (res_vec[j-1].size() > 0 && (dict.find(s.substr(j, i-j+1)) != dict.end()) ) {
                    for (auto it = res_vec[j-1].begin(); it != res_vec[j-1].end(); ++it) {
                        res_vec[i].push_back(*it + " " + s.substr(j, i-j+1));
                    } 
                }
            }
        }

        return res_vec[s.length() - 1];
    }
};
