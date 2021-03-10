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

class Solution {
private:
    struct data {
        int val;
        ListNode* next;
        data(int val, ListNode* next) : val(val), next(next) {}
        bool operator < (const data& x) const {
            return val > x.val;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return nullptr;
        }
        
        priority_queue<data> pq;
        
        for (ListNode* list: lists) {
            if (list) {
                pq.push(data(list->val, list->next));
            }
        }
        
        ListNode* ans = new ListNode();
        ListNode* prev = ans;
        
        while (!pq.empty()) {
            data cur = pq.top();
            pq.pop();
            
            prev->next = new ListNode(cur.val);
            
            if (cur.next) {
                pq.push(data(cur.next->val, cur.next->next));
            }
            
            prev = prev->next;
        }
        
        return ans->next;
    }
};
