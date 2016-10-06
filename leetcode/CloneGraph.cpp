/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    void dfs(UndirectedGraphNode *node, UndirectedGraphNode *newnode, map<UndirectedGraphNode *, UndirectedGraphNode *> &m) {
        m[node] = newnode;
        vector<UndirectedGraphNode *> &n = node->neighbors;
        vector<UndirectedGraphNode *> &newvec = newnode->neighbors;

        for (size_t i=0; i<n.size(); i++) {
            if (m.find(n[i]) != m.end()) {
                newvec.push_back(m[n[i]]);
            } else {
                UndirectedGraphNode *tmp = new UndirectedGraphNode(n[i]->label);
                newvec.push_back(tmp);
                dfs(n[i], tmp, m);
            }
        }
    
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;

        map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
        dfs(node, root, m);

        return root;
    }
};
