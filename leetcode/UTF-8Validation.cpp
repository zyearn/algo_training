class Solution {
public:
    bool match(vector<int>& data, int i, int num) {
        int index;
        int s = data.size();
        for (int j=0; j<num; j++) {
            index = i + j;
            if (index >= s) {
                return false;
            }
        
            if ((data[index] & 0xC0) != 0x80) {
                return false;
            }
        }

        return true;
    }

    bool validate(vector<int>& data, int *i) {
        int s = data.size();
        int tmpi = *i;
        if (tmpi >= s) {
            return true; 
        }

        int begin = data[tmpi];
        if ((begin & 0x80) == 0) {
            *i = *i + 1;
            return true;
        } else if ((begin & 0xE0) == 0xC0){
            *i = *i + 2;
            return match(data, tmpi+1, 1);
        } else if ((begin & 0xF0) == 0xE0) {
            *i = *i + 3;
            return match(data, tmpi+1, 2);
        } else if ((begin & 0xF8) == 0xF0) {
            *i = *i + 4;
            return match(data, tmpi+1, 3);
        } else {
            return false;
        }
    }

    bool validUtf8(vector<int>& data) {
        int i = 0;
        int s = data.size();
        bool res;

        while (i < s) {
            res = validate(data, &i);
            if (!res) {
                return false;
            }
        }

        return true;
    }
};
