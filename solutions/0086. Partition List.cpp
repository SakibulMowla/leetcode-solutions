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
    ListNode* partition(ListNode* head, int x) {
        ListNode before(0), after(0);
        ListNode* before_cur = &before;
        ListNode* after_cur = &after;

        while (head) {
            if (head->val < x) {
                before_cur->next = head;
                before_cur = head;
            } else {
                after_cur->next = head;
                after_cur = head;
            }
            head = head->next;
        }

        after_cur->next = nullptr;
        before_cur->next = after.next;

        return before.next;
    }
};
