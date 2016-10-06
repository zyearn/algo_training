/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 * 思路：设置两个指针，起初时都指向头结点，一个指针每次移动一步，另外一个指针每次移动两步，若两个指针相遇，则存在环
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *one_step, *two_step;
        one_step = two_step = head;

        while (two_step != NULL){
            one_step = one_step->next;
            two_step = two_step->next;
            if (two_step == NULL)
                return false;

            two_step = two_step->next;
            
            if (one_step == two_step)
                return true;
        }

        return false;
    }
};
