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
    int helper(TreeNode *root, int &max) {
        if (root == NULL) {
            return 0;
        }

        int lmax = helper(root->left, max);
        int rmax = helper(root->right, max);
        if (lmax < 0) lmax = 0;
        if (rmax < 0) rmax = 0;

        int c = lmax + rmax + root->val;
        if (c > max) max = c;

        root->val += (lmax > rmax) ? lmax: rmax;
        return root->val;
    } 

    int maxPathSum(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int max = root->val;

        helper(root, max);
        return max;
    }
};
