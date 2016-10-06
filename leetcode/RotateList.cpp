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
    ListNode* rotateRight(ListNode* head, int k) {
        // is one-time traversal possible?
        if (head == NULL)   return NULL;

        int size = 1;
        ListNode *curHead = head;
        while (curHead->next) {
            size++;
            curHead = curHead->next;
        }
        ListNode *tailNode = curHead;

        k %= size;
        k = (size - k) % size;
        curHead = head;
        ListNode *preNode = NULL;

        while (k-- > 0) {
            preNode = curHead;
            curHead = curHead->next;
        }

        if (!preNode) return head;

        tailNode->next = head;
        preNode->next = NULL;

        return curHead;
    }
};
