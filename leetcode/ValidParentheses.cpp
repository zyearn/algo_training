class Solution {
public:
    bool isLeft(char c) {
        if (c == '(' || c == '[' || c == '{')
            return true;

        return false;
    }

    bool isRight(char c) {
        if (c == ')' || c == ']' || c == '}')
            return true;

        return false;
    }

    bool isMatch(char l, char r) {
        if ((l == '(' && r == ')') ||
                (l == '[' && r == ']') ||
                (l == '{' && r == '}')) {
            return true;
        }

        return false;
    }
    
    bool isValid(string s) {
        size_t len = s.size(); 
        stack<char> st;
        char c, p;

        for (size_t i = 0; i < len; i++) {
            c = s[i];

            if (isLeft(c)) {
                st.push(c);
            } else if (isRight(c)){
                if (st.empty())
                    return false;

                p = st.top();
                st.pop();
                if (!isMatch(p, c))
                    return false;
            } else {
                return false;
            }
        }

        return (st.empty() == true);
    }
};
