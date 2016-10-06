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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        std::map<uint64_t, int> mCount;
        std::stack<TreeNode *> v;

        if (root == NULL) {
            return vector<int>();
        }

        v.push(root);
        TreeNode *tmp;
        while (!v.empty()) {
            tmp = v.top(); v.pop();
            mCount[(uint64_t)tmp]++;
            if (mCount[(uint64_t)tmp] == 1) {
                v.push(tmp);
                if (tmp->right != NULL) v.push(tmp->right);
                if (tmp->left != NULL) v.push(tmp->left);
            } else if (mCount[(uint64_t)tmp] == 2) {
                result.push_back(tmp->val); 
            }
        }

        return result;
    }
};
