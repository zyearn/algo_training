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
    int max(int a, int b) {
        return (a>b)?a:b;
    }

    int rob(TreeNode* root) {
        if (!root) return 0;

        rob(root->left);
        rob(root->right);

        int sum = 0;
        if (root->left && root->left->left) sum += root->left->left->val;
        if (root->left && root->left->right) sum += root->left->right->val;

        if (root->right && root->right->left) sum += root->right->left->val;
        if (root->right && root->right->right) sum += root->right->right->val;

        int ls = (root->left)? root->left->val: 0;
        int rs = (root->right)? root->right->val: 0;
        root->val = max(sum + root->val, ls + rs);

        return root->val;
    }

};
