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

    bool isBalanced(TreeNode* root) {
        if (root == NULL)  {
            return true;
        }

        if (!root->left && !root->right) {
            root->val = 1;
            return true;
        }

        if (!isBalanced(root->left) || !isBalanced(root->right)) {
            return false;
        }

        int hl = 0, hr = 0;

        if (root->left) {
            hl = root->left->val;
        }

        if (root->right) {
            hr = root->right->val;
        }

        int diff = hl - hr;
        if (diff >= -1 && diff <= 1) {
            root->val = max(hl, hr) + 1;
            return true;
        }

        return false;
    }
};
