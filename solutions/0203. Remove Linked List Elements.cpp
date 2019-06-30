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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        ListNode* prev = NULL;

        while (cur) {
            if (cur->val == val) {
                ListNode* tmp = cur;
                while (cur && cur->val == val) {
                    cur = cur->next;
                }
                if (prev) {
                    prev->next = cur;
                } else {
                    prev = cur;
                    head = prev;
                }
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        
        return head;
    }
};
