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
    TreeNode* _flatten(TreeNode *root) {
        if (root->left == NULL && root->right == NULL) {
            return root;
        }

        if (root->right == NULL) {
            root->right = root->left;
            root->left = NULL;
            return _flatten(root->right);
        }

        if (root->left == NULL) {
            return _flatten(root->right);
        }

        TreeNode *pLast = _flatten(root->left);
        TreeNode *pRet = _flatten(root->right);

        TreeNode *pRight = root->right;
        root->right = root->left;
        root->left = NULL;
        pLast->right = pRight;

        return pRet;
    }

    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        _flatten(root);
        return;
    }
};
