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
    void helper(TreeNode *root, int sum, int curSum, vector<int> &v, vector< vector<int> > &result) {
        if (!root) {
            return;
        }

        v.push_back(root->val);
        curSum += root->val;

        if (!root->left && !root->right) {
            // leaf
            if (curSum == sum) {
                result.push_back(v);
            }

        } else {
            helper(root->left, sum, curSum, v, result);
            helper(root->right, sum, curSum, v, result);
        }

        curSum -= root->val;
        v.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        int curSum = 0;
        vector<int> v;
        vector< vector<int> > result;

        helper(root, sum, curSum, v, result);
        return result;
    }
};


