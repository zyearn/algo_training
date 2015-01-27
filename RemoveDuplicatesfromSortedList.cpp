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
    void remove(ListNode *node) {
        ListNode *tmp = node->next;
        node->next = tmp->next;
        delete tmp;
    }
    
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *begin = head;
        while (head != NULL && head->next != NULL) {
            if (head->val == head->next->val){
                remove(head);
            } else {
                head = head->next;
            }
        }

        return begin;
    }
};

