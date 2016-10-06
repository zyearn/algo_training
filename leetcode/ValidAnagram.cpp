class Solution {
public:
    bool isAnagram(string s, string t) {
        int c[26] = {0};

        int ss = s.size();
        int st = t.size();

        if (ss != st) {
            return false;
        }

        for (size_t i=0; i<ss; i++) {
            c[s[i] - 'a']++;
            c[t[i] - 'a']--;
        }

        for (int i=0; i<26; i++) {
            if (c[i] != 0) return false;
        }

        return true;
    }
};
