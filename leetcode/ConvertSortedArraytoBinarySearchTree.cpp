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
    TreeNode* createBST(vector<int>& nums, int low, int high) {
        if (low > high)
            return NULL;
    
        int middle = (low+high) / 2;
        TreeNode *node = new TreeNode(nums.at(middle));

        node->left = createBST(nums, low, middle-1);
        node->right = createBST(nums, middle+1, high);
        
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums, 0, nums.size()-1);    
    }
};
