/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
class Solution {
public:
    int size(TreeNode *root) {
        if (root == NULL) {
            return 0;
        } else {
            return size(root->left) + size(root->right) + 1;
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        while (root) {
            int lSize = size(root->left);
            if (k <= lSize) {
                root = root->left;
            } else if (k == lSize + 1) {
                return root->val;
            } else {
                root = root->right;
                k = k - lSize - 1;
            }
        }

        return 0;
    }
};
*/

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> st;
        TreeNode *cur = root;

        while (cur || !st.empty()) {
            
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();

            if (--k == 0) {
                return cur->val;
            }

            cur = cur->right;
        }
    }
};
