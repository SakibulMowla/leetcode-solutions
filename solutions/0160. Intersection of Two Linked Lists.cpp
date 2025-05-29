/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time - O(n + m)
// Memory - O(n + m)

class Solution {
private:
    vector<ListNode*> getAllNode(ListNode* head) {
        vector<ListNode*> ret;
        while (head) {
            ret.push_back(head);
            head = head->next;
        }
        return ret;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> aNodes = getAllNode(headA);
        vector<ListNode*> bNodes = getAllNode(headB);

        int m = (int)aNodes.size() - 1, n = (int)bNodes.size() - 1;
        ListNode* ans = nullptr;
        while (m >= 0 && n >= 0) {
            if (aNodes[m] != bNodes[n]) {
                break;
            }
            ans = aNodes[m];
            m--;
            n--;
        }

        return ans;
    }
};

// ------------------------------------------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time - O(n + m)
// Memory - O(1)

class Solution {
private:
    int findLen(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = findLen(headA);
        int lenB = findLen(headB);

        // advance in the longer list
        while (lenA != lenB) {
            if (lenA < lenB) {
                headB = headB->next;
                lenB--;
            } else {
                headA = headA->next;
                lenA--;
            }
        }

        // advance until common is found
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};

// ------------------------------------------------------------------------

// Time - O(n + m)
// Memory - O(1)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }

        return pA;
    }
};
