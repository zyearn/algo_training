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
    int h_(TreeNode *root, int *psmall, int *pbig) {
        int l, r;
        int ret;
        *psmall = *pbig = root->val;

        if (root->left) {
            ret = h_(root->left, &l, &r);
            if (ret < 0) return -1;
            if (r >= root->val) return -1;
            *psmall = l;
        }

        if (root->right) {
            ret = h_(root->right, &l, &r);
            if (ret < 0) return -1;
            if (l <= root->val) return -1;
            *pbig = r;
        }

        return 0;
    }

    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        int l, r;

        int ret = h_(root, &l, &r);
        return (ret == 0)? true: false;
    }
};
