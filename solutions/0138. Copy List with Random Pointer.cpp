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
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> dupMap;
        Node* headCopy = head;
        
        while (head) {
            if (dupMap.find(head) == dupMap.end()) {
                dupMap[head] = new Node(head->val);
            }
            Node* dupHead = dupMap[head];

            if (head->random && dupMap.find(head->random) == dupMap.end()) {
                dupMap[head->random] = new Node(head->random->val);
            }
            dupHead->random = head->random ? dupMap[head->random] : nullptr;
            
            if (head->next && dupMap.find(head->next) == dupMap.end()) {
                dupMap[head->next] = new Node(head->next->val);
            }
            dupHead->next = head->next ? dupMap[head->next] : nullptr;

            head = head->next;
        }

        return dupMap[headCopy];
    }
};
