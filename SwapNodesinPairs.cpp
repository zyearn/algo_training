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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode *result =  (head->next)?head->next: head;
        
        ListNode *cur = head;
        ListNode *prev = NULL;
        ListNode *tmp;

        while (cur && cur->next) {
            tmp = cur->next->next;

            if (prev) {
                prev->next = cur->next;
            }

            cur->next->next = cur;
            cur->next = tmp;

            prev = cur;
            cur = cur->next;
        }

        return result;

    }
};
