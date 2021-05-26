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
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = nullptr;
        ListNode* newHead = nullptr;
        
        while (head) {
            if (head->val == val) {
                if (prev) {
                    prev->next = head->next;
                }
            } else {
                prev = head;
                if (!newHead) {
                    newHead = head;
                }
            }
            head = head->next;
        }
        
        return newHead;
    }
};
