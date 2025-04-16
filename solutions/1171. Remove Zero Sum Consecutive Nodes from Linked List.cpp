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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> sumToNode;

        ListNode* dummy = new ListNode();
        sumToNode[0] = dummy;
        dummy->next = head;

        int sum = 0;
        while (head) {
            sum += head->val;
            if (sumToNode.find(sum) != sumToNode.end()) {
                // Remove the prefix sum to node entry for the nodes
                // getting removed
                ListNode* nodeToRemove = sumToNode[sum]->next;
                int tempSum = sum;
                while (nodeToRemove != head) {
                    tempSum += nodeToRemove->val;
                    sumToNode.erase(tempSum);
                    nodeToRemove = nodeToRemove->next;
                }
                
                sumToNode[sum]->next = head->next;
            } else {
                sumToNode[sum] = head;
            }
            head = head->next;
        }

        return dummy->next;
    }
};
