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
    bool _isSym(TreeNode *rl, TreeNode *rr) {
        if (rl == NULL && rr == NULL) return true;
        if (rl == NULL || rr == NULL) return false;
        if (rl->val != rr->val) return false;

        return _isSym(rl->left, rr->right) && _isSym(rl->right, rr->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        return _isSym(root->left, root->right);
    }
};
