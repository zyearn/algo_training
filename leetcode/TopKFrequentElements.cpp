#include <map>
#include <queue>
#include <iostream>
using namespace std;

class Solution {

public:
    struct obpair {
        int i;
        int t;
    };
    
    struct comp {
        bool operator()(const obpair &o1, const obpair &o2) {
            return (o1.t > o2.t);
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> m;
        std::priority_queue<obpair, std::vector<obpair>, comp> min_heap;
        obpair obtmp;

        for (int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }

        for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            obtmp.i = it->first;
            obtmp.t = it->second;

            if (min_heap.size() < k) {
                min_heap.push(obtmp);
            } else if (min_heap.top().t < it->second) {
                min_heap.pop();
                min_heap.push(obtmp);
            }
        }

        vector<int> res;

        while (!min_heap.empty()) {
            res.push_back(min_heap.top().i);
            min_heap.pop();
        }
        
        return res;
    }
};

int main() {
    vector<int> nums{5,2,5,3,5,3,1,1,3};
    Solution s;
    vector<int> res(s.topKFrequent(nums, 2));

    for (int i=0; i<res.size(); i++) {
        cout << res[i] << " ";
    }

    cout << endl;
    return 0;
}
