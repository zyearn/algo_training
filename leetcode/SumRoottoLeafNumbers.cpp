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
    void helper(TreeNode *root, int &curSum, int &sum) {
        if (!root) {
            return;
        }

        curSum = curSum * 10 + root->val;
        if (!root->left && !root->right) {
            // leaf
            sum += curSum;
        } else {
            helper(root->left, curSum, sum);
            helper(root->right, curSum, sum);
        }

        curSum /= 10;
    }

    int sumNumbers(TreeNode *root) {
        int sum = 0;
        int curSum = 0;

        // DFS
        helper(root, curSum, sum);
        return sum;
    }
};
