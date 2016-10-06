/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> st_m;

    void pushAll(TreeNode *node) {
        for(; node != NULL; node = node->left) {
            st_m.push(node);
        }
    }

public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return st_m.size() != 0;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *ret = st_m.top();
        st_m.pop();
        pushAll(ret->right);
        return ret->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
