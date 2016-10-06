/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    void getNodeInfo(ListNode *head, int n, ListNode **last, ListNode **info, ListNode **slast) {
        *last = *info = *slast = NULL;

        for (int i=0; i<n-1 && head; i++) {
            head = head->next;
        }

        if (head) *last = head;
        if (!head || !head->next) {
            return;
        } else {
            *info = head->next;
            head = head->next;
        }

        for (int i=0; i<n-1 && head->next; i++) {
            head = head->next; 
        }

        *slast = head;
    }

    ListNode *merge(ListNode *p, ListNode *q, ListNode **last) {
        ListNode *vhead = new ListNode(0);
        ListNode *chead = vhead;

        while (p && q) {
            if (p->val < q->val) {
                chead->next = p;
                p = p->next;
            } else {
                chead->next = q;
                q = q->next;
            }
            chead = chead->next;
        }

        if (p) {
            chead->next = p;
        } else {
            chead->next = q;
        }

        while (chead->next) {
            chead = chead->next;
        }

        *last = chead;
        return vhead->next;
    }

public:
    ListNode* sortList(ListNode *head) {
        int block_size = 1;
        ListNode *vhead = new ListNode(0);
        ListNode *chead = vhead;
        vhead->next = head;

        ListNode *last, *info, *slast;

        while (1) {
            chead = vhead;
            getNodeInfo(chead->next, block_size, &last, &info, &slast);
            if (!info)
                break;
            
            ListNode *snext;
            ListNode *plast;
            while (1) {
                last->next = NULL;
                snext = slast->next;
                slast->next = NULL;
                chead->next = merge(chead->next, info, &plast);
                plast->next = snext;
                chead = plast;
                getNodeInfo(chead->next, block_size, &last, &info, &slast);
                if (!info) {
                    break;
                }
            }

            block_size *= 2;
        }

        return vhead->next;
    }
};
