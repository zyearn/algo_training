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
        if (!root) return;

        TreeLinkNode *pL = root->left;
        TreeLinkNode *pR = root->right;

        while (pL && pR) {
            pL->next = pR;

            pL = pL->right;
            pR = pR->left;
        }

        connect(root->left);
        connect(root->right);
        
        return;
    }
};
