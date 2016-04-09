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
    string genString(vector<TreeNode *> &onstack) {
        size_t sz = onstack.size();
        if (sz == 0) return "";

        char buf[128];
        string str;
        snprintf(buf, 128, "%d", onstack[0]->val);
        str += buf;

        for (int i=1; i<sz; i++) {
            snprintf(buf, 128, "%d", onstack[i]->val);
            str += "->";
            str += buf;
        }

        return str;
    }

    void dfs(TreeNode *root, vector<TreeNode *> &onstack, vector<string> &res) {
        onstack.push_back(root);
        if (root->left == NULL && root->right == NULL) {
            res.push_back(genString(onstack));
        }

        if (root->left) {
            dfs(root->left, onstack, res);
        }
        
        if (root->right){
            dfs(root->right, onstack, res);
        }
        
        onstack.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<TreeNode *> onstack;
        vector<string> res;

        if (root)
            dfs(root, onstack, res);

        return res;
    }
};
