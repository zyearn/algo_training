/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    struct Node {
        int index;
        ListNode *addr;
    };

    class Compare {
        public:
        bool operator() (Node a, Node b){
            return a.addr->val >= b.addr->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<Node, std::vector<Node>, Compare> pq;
        int len = lists.size();
        struct Node n;
        ListNode *head, *tail;
        head = tail = NULL;

        for (int i=0; i<len; i++) {
            if (lists[i] != NULL) {
                n.index = i;
                n.addr = lists[i];
                pq.push(n); 
                lists[i] = lists[i]->next;
            }
        }

        struct Node minNode;
        while (!pq.empty()) {
            minNode = pq.top();
            pq.pop();

            if (head == NULL) {
                head = tail = minNode.addr;
            } else {
                tail->next = minNode.addr;
                tail = tail->next;
            }

            if (lists[minNode.index]) {
                minNode.addr = lists[minNode.index];
                pq.push(minNode);
                lists[minNode.index] = lists[minNode.index]->next;
            }
        }
        
        if (tail) tail->next = NULL;

        return head;
    }
};

int main() {
    ListNode *ln = (ListNode *) malloc(sizeof(ListNode) * 7);
    ln[0].val = 4;
    ln[0].next = &ln[1];

    ln[1].val = 7;
    ln[1].next = &ln[2];

    ln[2].val = 9;
    ln[2].next = NULL;

    ln[3].val = 1;
    ln[3].next = &ln[4];

    ln[4].val = 5;
    ln[4].next = &ln[5];

    ln[5].val = 8;
    ln[5].next = NULL;

    vector<ListNode *> list{&ln[0], &ln[3]};
    Solution s;
    ListNode *head = s.mergeKLists(list);

    for (; head; head=head->next) {
        cout << head->val << endl;
    }

    free(ln);
    return 0;
}
