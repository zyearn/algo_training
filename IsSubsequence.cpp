class Solution {
public:
    bool isSubsequence(string s, string t) {
        set<char> st;
        vector<char> v;

        int tsize = t.size();
        int ssize = s.size(); 
        
        if (ssize > tsize) {
            return false;
        }

        for (int i=0; i<tsize; i++) {
            if (st.find(t[i]) != st.end()) {
                continue;
            }

            st.insert(t[i]);
            v.push_back(t[i]);
        }

        int i=0, j=0;
        while (i<ssize && j<tsize) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        return (i == ssize);
    }
};
