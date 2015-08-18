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

        queue<TreeLinkNode *> qtmp;
        queue<TreeLinkNode *> qcur;
        TreeLinkNode *ptmp;

        qcur.push(root);
        while(1) {
            while (!qcur.empty()) {
                ptmp = qcur.front();
                qcur.pop();

                if (ptmp->left) qtmp.push(ptmp->left);
                if (ptmp->right) qtmp.push(ptmp->right);

                if (qcur.size() > 0) {
                    ptmp->next = qcur.front();
                } else {
                    ptmp->next = NULL;
                }
            }

            if (qtmp.size() == 0) {
                break;
            }

            qtmp.swap(qcur);
        }
        
        return;
    }
};
