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
    int findLenght(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int len = findLenght(head);
        if (len) k %= len;
        
        ListNode* first = head;
        ListNode* second = head;
        int cnt = 0;

        while (first) {
            if (first->next) {
                first = first->next;
                cnt++;
                if (cnt > k) {
                    second = second->next;
                }
            } else {
                first->next = head;
                head = second->next;
                second->next = NULL;
                break;
            }
        }
        
        return head;
    }
};
