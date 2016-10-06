class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> stoi(256, -1);
        vector<char> ttoi(256, -1);

        for (size_t i=0; i<s.size(); i++) {
            if (stoi[s[i]] != ttoi[t[i]]) return false;

            stoi[s[i]] = ttoi[t[i]] = i;
        }

        return true;
    }
};
