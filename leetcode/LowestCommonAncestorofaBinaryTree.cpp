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
#include <iostream>
#include <map>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode *root, int curdeep, map<TreeNode *, TreeNode *> &mf, map<TreeNode *, int> &md) {
        if (root->left) {
            mf[root->left] = root;
            md[root->left] = curdeep + 1;
            dfs(root->left, curdeep + 1, mf, md);
        }
        
        if (root->right) {
            mf[root->right] = root;
            md[root->right] = curdeep + 1;
            dfs(root->right, curdeep + 1, mf, md);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q)
            return NULL;

        map<TreeNode *, TreeNode *> mf;
        map<TreeNode *, int> md;
        mf[root] = NULL;
        md[root] = 0;

        dfs(root, 0, mf, md);

        int ph, qh;

        while (1) {
            if (p == q) {
                return p;
            }

            ph = md[p];
            qh = md[q];

            if (ph > qh) {
                p = mf[p];
            } else if (qh > ph) {
                q = mf[q];
            } else {
                p = mf[p];
                q = mf[q];
            }
        }
    }
};

int main() {
    return 0;
}
*/


class Solution {
public:
    //lowestCommonAncestor表示在root为根的二叉树中，若p、q存在于该树种，那么返回p、q的LCA
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == NULL) {
            return root;
        }
           
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right) {
            return root;
        } else if (left) {
            return left;
        } else {
            return right;
        }
    }
};
