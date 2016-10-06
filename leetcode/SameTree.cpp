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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // there is only one NULL in p and q
        if ( (p == NULL && q != NULL) || (p != NULL && q == NULL) )
        return false;
        
        //both NULL
        if (p == NULL)
        return true;
        
        //recusively compare leftsubtree and rightsubtree
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        
        // if any subtree is false return false
        if (!left || !right)
        return false;
        
        if (p->val != q->val)
        return false;
        
        return true;
    }
};
