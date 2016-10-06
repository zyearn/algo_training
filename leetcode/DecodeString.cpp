class Solution {
public:
    string work(string &s, int *curi) {
        int i = *curi;
        string res;

        if (s[i] >= '0' && s[i] <= '9') {
            int num = 0;
            
            while (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            i = i+1;
            string tmpstr;
            while (s[i] != ']') {
                if (s[i] >= '0' && s[i] <= '9') {
                    tmpstr += work(s, &i);
                } else {
                    tmpstr += s[i];
                    i++;
                }
            }

            for (int j=0; j<num; j++) {
                res += tmpstr;
            }

            *curi = i+1;
        } else {
            
            while (i<s.size() && (s[i] <'0' || s[i] > '9')) {
                res += s[i];
                i++;
            }

            *curi = i;
        }
        
        return res;

    }

    string decodeString(string s) {
        int i = 0;
        int ss = s.size();
        string res;
        
        while (i < ss) {
            res += work(s, &i);
        }

        return res;
    }
};
