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
// Memory - O(n)

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        while (head) {
            nodes.push_back(head);
            head = head->next;
        }

        ListNode* prev = new ListNode();

        int l = 0, r = (int)nodes.size() - 1;
        bool fromFront = true;

        while (l <= r) {
            if (fromFront) {
                prev->next = nodes[l++];
            } else {
                prev->next = nodes[r--];
            }

            prev = prev->next;
            prev->next = nullptr;
            fromFront = !fromFront;
        }

        return;
    }
};

// -------------------------------------------------

// Time - O(n)
// Memory - O(1)

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
    void reorderList(ListNode* head) {
        // find the middle of the list
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second half of the list
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;

        while (second) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        // merge the 2 lists
        ListNode* first = head;
        second = prev;
        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }

        return;
    }
};
