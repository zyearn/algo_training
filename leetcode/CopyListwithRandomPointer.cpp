/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*, RandomListNode*> m;

        if (!head) return NULL;
        RandomListNode *new_head = (RandomListNode *)malloc(sizeof(RandomListNode));
        new_head->label = head->label;
        RandomListNode *new_cur = new_head;
        m[head] = new_head;
        m[NULL] = NULL;

        RandomListNode *tmp;
        while (head) {
            if (m.find(head->random) != m.end()) {
                new_cur->random = m[head->random];
            } else {
                tmp = (RandomListNode *)malloc(sizeof(RandomListNode));
                tmp->label = head->random->label;
                m[head->random] = tmp;
                new_cur->random = tmp;
            }

            head = head->next;
            if (m.find(head) != m.end()) {
                new_cur->next = m[head];
            } else {
                tmp = (RandomListNode *)malloc(sizeof(RandomListNode));
                tmp->label = head->label;
                m[head] = tmp;
                new_cur->next = tmp;
            }
            new_cur = new_cur->next;
        }

        return new_head;
    }
};
