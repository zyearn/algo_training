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
    ListNode* oddEvenList(ListNode* head) {
        bool isOdd = true;
        ListNode *pOdd = head;
        ListNode *pEven = (head)? head->next: NULL;
        ListNode *pEvenstart = pEven;
        ListNode *pCur = (pEven)? pEven->next: NULL;
        ListNode *pTmp;

        while (pCur) {
            pTmp = pCur->next;
            if (isOdd) {
                pOdd->next = pCur;
                pOdd = pCur;
            } else {
                pEven->next = pCur;
                pEven = pCur;
            }

            isOdd = !isOdd;
            pCur = pTmp;
        }

        if (head) pOdd->next = pEvenstart;
        if (pEvenstart) pEven->next = NULL;

        return head;
    }
};


int main() {
    ListNode *phead = (ListNode *)malloc(sizeof(ListNode) * 3);
    phead[0].val = 1;
    phead[0].next = &phead[1];
    phead[1].val = 2;
    phead[1].next = &phead[2];
    phead[2].val = 3;
    phead[2].next = NULL;

    Solution s;
    phead = s.oddEvenList(phead);

    while (phead) {
        cout << phead->val << endl;
        phead = phead->next;
    }

    return 0;
}
