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
    ListNode* findFirstHalfEnd(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* nextTemp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextTemp;
        }
        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }
        
        ListNode* firstHalfEnd = findFirstHalfEnd(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);
        
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        
        bool ans = true;
        while (p2) {
            if (p1->val != p2->val) {
                ans = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        firstHalfEnd->next = reverseList(secondHalfStart);
        
        return ans;
    }
};
