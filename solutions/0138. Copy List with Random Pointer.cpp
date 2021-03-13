/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dupHead = NULL;
        Node* pre = NULL;
        
        unordered_map<Node*, Node*> dupMap;

        while (head) {
            if (dupMap.find(head) == dupMap.end()) {
                dupMap[head] = new Node(head->val);
            }
            if (pre) {
                pre->next = dupMap[head];
            } else {
                dupHead = dupMap[head];
            }
            if (head->random && dupMap.find(head->random) == dupMap.end()) {
                dupMap[head->random] = new Node(head->random->val);
            }
            dupMap[head]->random = dupMap[head->random];
            pre = dupMap[head];
            head = head->next;
        }
        
        return dupHead;
    }
};
