/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result;
        if (l1 && l2) {
            result = (l1->val < l2->val)?l1:l2; 
        } else if (l1) {
            return l1;
        } else if (l2) {
            return l2;
        } else {
            return NULL;
        }

        ListNode *prev = NULL;
        ListNode *tmp = NULL;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tmp = l1;
                l1 = l1->next;
            } else {
                tmp = l2;
                l2 = l2->next;
            }

            if (prev == NULL) {
                prev = tmp;
            } else {
                prev->next = tmp;
                prev = tmp;
            }
        }


        if (l1 && prev) {
            prev->next = l1;
        }

        if (l2 && prev) {
            prev->next = l2;
        }

        return result;
    }
};
