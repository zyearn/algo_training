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
        if (root == NULL)
            return;

        queue<TreeLinkNode *> q;
        q.push(root);
        q.push(NULL);

        TreeLinkNode *pCur;
        while (!q.empty()) {
            pCur = q.front();
            q.pop();

            if (pCur == NULL) {
                if (q.size() > 0) q.push(NULL);
            } else {
                pCur->next = q.front();

                if (pCur->left) q.push(pCur->left);
                if (pCur->right) q.push(pCur->right);
            }
        }

        return;
    }
};
