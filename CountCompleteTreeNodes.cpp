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
    int height(TreeNode *root) {
        if (!root) return -1;
        else return height(root->left) + 1;
    }

    int countNodes(TreeNode* root) {
        int nodes = 0;
        int h, hr;

        while (root != NULL) {
            h = height(root);
            hr = height(root->right);
            if (hr == h - 1) {
                // root->left is full
                nodes += 1 << h;
                root = root->right;
            } else {
                nodes += 1 << (h - 1);
                root = root->left;
            }
        }

        return nodes;
    }
};
