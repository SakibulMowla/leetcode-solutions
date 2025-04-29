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

// Time - O(n)
// memory - O(n)

class Solution {
private:
    int findLen(ListNode* cur) {
        int len = 0;
        while (cur) {
            len++;
            cur = cur->next;
        }
        return len;
    }

    void removeNthFromFront(ListNode* cur, int left) {
        if (left == 0) {
            cur->next = cur->next->next;
            return;
        }

        removeNthFromFront(cur->next, left - 1);
    }    

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = findLen(head);
        int targetIndexFromFront = len - n;

        ListNode* dummy = new ListNode();
        dummy->next = head;

        removeNthFromFront(dummy, targetIndexFromFront);

        return dummy->next;
    }
};

// ------------------------------------------------------

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

// Time - O(n)
// memory - O(1)

class Solution {
private:
    int findLen(ListNode* cur) {
        int len = 0;
        while (cur) {
            len++;
            cur = cur->next;
        }
        return len;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = findLen(head);
        int targetIndexFromFront = len - n;

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = dummy;

        while (targetIndexFromFront) {
            cur = cur->next;
            targetIndexFromFront--;
        }

        cur->next = cur->next->next;

        return dummy->next;
    }
};
