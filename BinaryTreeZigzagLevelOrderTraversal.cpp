/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }

        TreeNode *pDelim = NULL;
        TreeNode *cur;
        queue<TreeNode *> q;
        q.push(root);
        q.push(pDelim);
        
        vector<int> vCur;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            
            if (cur == NULL) {
                res.push_back(vCur);
                
                if (q.size() > 0) {
                    q.push(pDelim);
                }

                vCur.clear();
                continue;
            }

            if (cur->left != NULL) q.push(cur->left);
            if (cur->right != NULL) q.push(cur->right);

            vCur.push_back(cur->val);
        }

        for (int i=1; i<res.size(); i=i+2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};
