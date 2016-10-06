#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>> &edges, vector<bool> &marked, vector<int> &postorder, vector<bool> &onstack) {
        marked[node] = true;
        onstack[node] = true;
        vector<int> &adjs = edges[node];

        for (size_t i=0; i<adjs.size(); i++) {
            if (onstack[adjs[i]]) {
                // find cycle
                return false;
            }

            if (!marked[adjs[i]] && !dfs(adjs[i], edges, marked, postorder, onstack)) {
                return false;
            }
        }

        postorder.push_back(node);
        onstack[node] = false;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> edges(numCourses, vector<int>());

        for (size_t i=0; i<prerequisites.size(); i++) {
            pair<int, int> &p = prerequisites[i];
            edges[p.second].push_back(p.first);
        }

        vector<bool> marked(numCourses, false);
        vector<bool> onstack(numCourses, false);
        vector<int> postorder;

        for (int i=0; i<numCourses; i++) {
            if (!marked[i] && !dfs(i, edges, marked, postorder, onstack)) {
                return vector<int>();
            }
        }

        int tmp;
        for (size_t i=0, j=postorder.size()-1; i<j; i++, j--) {
            tmp = postorder[i];
            postorder[i] = postorder[j];
            postorder[j] = tmp;
        }

        return postorder;
    }
};

int main() {
    vector<pair<int, int>> p;
    p.push_back(make_pair(1, 0));


    Solution s;
    vector<int> res(s.findOrder(2, p));

    for (size_t i=0; i<res.size(); i++) {
        cout << res[i] << endl;
    }
}
