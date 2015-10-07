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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        TreeNode *pFront = NULL, *pLast = NULL;
        while (!q.empty()) {
            pFront = q.front();
            q.pop();
    
            if (pFront == NULL) {
                res.push_back(pLast->val);
                if (q.size() > 0) {
                    q.push(NULL);
                }
            } else {
                pLast = pFront;
                if (pLast->left) q.push(pLast->left);
                if (pLast->right) q.push(pLast->right);
            }
        }

        return res;
    }
};
