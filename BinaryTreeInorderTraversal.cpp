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
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> ans;
        map<TreeNode *, int> mapcount;

        if (root == NULL)
            return ans;

        st.push(root);
        TreeNode *cur;
        while (!st.empty()){
            rur = st.top(); st.pop();

            if (mapcount[cur] == 0)
            {
                //ans.push_back(cur->val);
                if (cur->right) st.push(cur->right);
                st.push(cur);
                mapcount[cur]++;
                if (cur->left) st.push(cur->left);
            } else {
                ans.push_back(cur->val);
            }
        }

        return ans;
    }
};
