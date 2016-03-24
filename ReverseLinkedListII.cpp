/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    void reverseList(ListNode* head, int k, ListNode **s, ListNode **n) {
        if (!head) return;
        ListNode *prev = NULL;
        ListNode *next = NULL;

        while (head && k > 0) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
            k--;
        }
        
        *s = prev;
        *n = next;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (n < m || m < 1 || n < 1) return NULL;

        ListNode *ohead = new ListNode(0);
        ohead->next = head;
        head = ohead;
        int tm = m;
        while (head && --tm > 0) {
            head = head->next;
        }

        if (!head) return ohead->next;

        ListNode *tail = head->next;
        ListNode *s = NULL, *e = NULL;
        reverseList(tail, n - m + 1, &s, &e);
        head->next = s;
        if (tail) tail->next = e;

        return ohead->next;
    }
};

int main() {
    ListNode *l = (ListNode *)malloc(sizeof(ListNode) * 3);
    l[0].val = 1;
    l[0].next = &l[1];
    l[1].val = 2;
    l[1].next = &l[2];
    l[2].val = 3;
    l[2].next = NULL;

    Solution s;
    l = s.reverseBetween(l, 1, 1);

    ListNode *h = l;
    while (h) {
        cout << h->val << endl;
        h = h->next;
    }

}
