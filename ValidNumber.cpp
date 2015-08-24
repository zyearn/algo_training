/*
#include <iostream>
#include <cctype>
using namespace std;
*/

class Solution {
public:
    string trim(const std::string& str,
            const std::string& whitespace = " \t") {
        std::size_t strBegin = str.find_first_not_of(whitespace);
        if (strBegin == std::string::npos) {
            return "";
        }

        std::size_t strEnd = str.find_last_not_of(whitespace);
        int strRange = strEnd - strBegin + 1;

        return str.substr(strBegin, strRange);
    }

    bool isNumber(string s) {
        s = trim(s);

        enum {
            start = 0,
            bfdot,
            afdot,
            afdotNeedNumber,
            e,
            eop,
            edigit
        } state;

        state = start;
        char c;

        for (int i=0; i<s.length(); i++) {
            c = s[i];

            switch(state) {
                case start:
                    if (isspace(c)) {
                        return false;
                    }

                    if (isdigit(c)) {
                        state = bfdot;
                        break;
                    }

                    if (c == '.') {
                        state = afdotNeedNumber;
                        break;
                    }

                    if (c == '+' || c == '-') {
                        break;
                    }

                    return false;

                    break;
                case bfdot:
                    if (isspace(c)) {
                        return false;
                        break;
                    }

                    if (isdigit(c)) {
                        break;
                    }

                    if (c == '.') {
                        state = afdot;
                        break;
                    }

                    if (c == 'e') {
                        state = e;
                        break;
                    }

                    return false;

                case afdotNeedNumber:
                    if (isdigit(c)) {
                        state = afdot;
                        break;
                    }

                    return false;

                case afdot:
                    if (isspace(c)) {
                        return false;
                        break;
                    }

                    if (isdigit(c)) {
                        break;
                    }

                    if (c == 'e') {
                        state = e;
                        break;
                    }

                    return false;
                
                case e:
                    if (isdigit(c)) {
                        state = edigit;
                        break;
                    }

                    if (isspace(c)) {
                        return false;
                        break;
                    }

                    if (c == '+' || c == '-') {
                        state = eop;
                        break;
                    }

                    return false;

                case eop:

                    if (isdigit(c)) {
                        state = edigit;
                        break;
                    }

                    return false;
                
                case edigit:

                    if (isdigit(c)) {
                        break;
                    }

                    return false;
                default:
                    return false;
                    break;
            }
        }
        
        if (state == e || state == eop) {
            return false;
        }

        if (state == afdotNeedNumber) {
            return false;
        }

        return state != start;
    }
};

/*
int main() {
    Solution s;

    cout << s.isNumber("0") << endl;
    cout << s.isNumber(" 0.1 ") << endl;
    cout << s.isNumber("abc") << endl;
    cout << s.isNumber("1 a") << endl;
    cout << s.isNumber("2e10") << endl;
    cout << s.isNumber("1.1111e1111") << endl;
    cout << s.isNumber("1.11e") << endl;
    cout << s.isNumber("1.e") << endl;
    cout << s.isNumber(".") << endl;

    return 0;
}
*/
