class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        do {
            while (!isalnum(s[i]) && i < j) i++;
            while (!isalnum(s[j]) && i < j) j--;

            if (i<j && tolower(s[i]) != tolower(s[j]))
                return false;
            
            i++;
            j--;
        } while (i<j);
        return true;
    }
};
