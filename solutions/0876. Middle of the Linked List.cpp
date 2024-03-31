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

/*
Time - O(n)
Spaxe - O(1)
*/
class Solution {
private:
    int findLen(ListNode* head) {
        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }
        return len;
    }

    ListNode* nodeAt(int index, ListNode* head) {
        while (index--) {
            head = head->next;
        }
        return head;
    }

public:
    ListNode* middleNode(ListNode* head) {
        int len = findLen(head);
        return nodeAt(len / 2, head);
    }
};

// -------------------------------------------
/*
Slow and fast pointer approach
Time - O(n)
Spaxe - O(1)
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
