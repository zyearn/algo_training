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
    int min(int a, int b) {
        return (a<b)? a: b;
    }

    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->right && !root->left) return 1 + minDepth(root->right);
        if (root->left && !root->right) return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
