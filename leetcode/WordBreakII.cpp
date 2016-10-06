/*
��̬�滮����word break���ơ�
����Ĺؼ���Ҫ����word break�ķ������ж��Ƿ���Բ�֣�����������������������ȼ��ֱ��������MLE��
ת�Ʒ��̣�
��res_vec[n]Ϊ��s[n]Ϊ��β�Ӵ��Ľ⣨��һ��string��vector������ôres_vec[n] = res_vec[j]ÿ��Ԫ�� �� s[j+1]...s[n] ����ϣ�j=0...n-1 ���� s[0]...s[n] ��s[0]...s[n]��dict��.
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
