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
    void helper(TreeNode *root, int sum, int &curNum, bool &result) {
        // ROOT is empty or we have already found the answer
        if (!root || result) {
            return;
        }
        
        curNum += root->val;
        if (!root->left && !root->right) {
            // leaf
            result = (curNum == sum);
        } else {
            helper(root->left, sum, curNum, result);
            helper(root->right, sum, curNum, result);
        }

        curNum -= root->val;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        int curNum = 0;
        bool result = false;

        helper(root, sum, curNum, result);
        return result;
    }
};
