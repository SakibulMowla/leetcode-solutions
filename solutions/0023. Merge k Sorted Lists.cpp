/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct Comparator {
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comparator> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }
        
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            
            if (!head) {
                head = top;
            }
            if (prev) {
                prev->next = top;
            }
            prev = top;
            
            if (top->next) {
                pq.push(top->next);
            }
        }
        
        return head;
    }
};
