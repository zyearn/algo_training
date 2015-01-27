/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;

        auto parent = root, child = root->left;
        
        while (child) {
            auto back = child;

            while (child) {
                child->next = parent->right;
                child = child->next;
                parent = parent->next;
                child->next = parent?parent->left:NULL;
                child = child->next;
            }

            parent = back;
            child = parent->left;
        }
        
    }
};
