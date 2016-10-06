/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> ans;

        st.push(root);
        while (!st.empty()){
            TreeNode *cur = st.top();
            st.pop();

            if(cur != NULL){
                ans.push_back(cur->val);
                st.push(cur->right);
                st.push(cur->left);
            }
        }

        return ans;
    }
};
