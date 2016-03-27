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
    ListNode *reverseList(ListNode *head) {
        if (!head) {
            return NULL;
        }

        ListNode *pre = NULL;
        ListNode *next;

        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }

        return pre;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }

        ListNode *slow, *fast;
        slow = fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseList(slow->next);
        slow = slow->next;

        while (slow) {
            if (slow->val != head->val) {
                return false;
            }

            slow = slow->next;
            head = head->next;
        }

        return true;
    }
};
