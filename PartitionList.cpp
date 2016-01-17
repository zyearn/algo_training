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
  ListNode(){}
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *gList , *sList, *gTail, *sTail;
        gList = sList = gTail = sTail = NULL;

        for (ListNode *cur = head; cur; cur=cur->next) {
            if (cur->val < x) {
                if (sList == NULL) {
                    sList = cur;
                } else {
                    sTail->next = cur;
                }
                
                sTail = cur;
            } else {
                if (gList == NULL) {
                    gList = cur;
                } else {
                    gTail->next = cur;    
                }
                
                gTail = cur;
            }
        }

        if (sTail) { 
            sTail->next = gList;
            if (gTail) {
                gTail->next = NULL;
            }
            return sList;
        } else if (gTail){
            return gList;
        } else {
            return NULL;
        }
    }
};

int main() {
    ListNode l[2];
    l[0].val = 2;
    l[0].next = &l[1];
    l[1].val = 1;
    l[1].next = NULL;
    
    Solution s;
    ListNode *ret = s.partition(l, 2);

    for (ListNode *cur=ret; cur; cur=cur->next) {
        cout << cur->val << endl;
    }

    return 0;
    
}
