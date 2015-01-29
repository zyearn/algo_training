/*
   Majority number ��ռ�ݡ�������number��iλ�ĺͣ���majority number��ӦλΪ1����ô��һλ�������ܺͱȴ���num.size() / 2
*/
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int result = 0;
        for (int i=0; i<32; i++) {
            int sum = 0;
            for (std::vector<int>::iterator it = num.begin(); it!=num.end(); ++it) {
                sum += ((*it) >> i) & 1;
            }
            
            if (sum > num.size()/2)
                result |= (1 << i);
        }

        return result;
    }
};
