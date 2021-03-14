/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* prev;
    Node* head;

    void addDoublyList(int val) {
        Node* now = new Node(val);
        if (prev) {
            prev->right = now;
            now->left = prev;
        } else {
            head = now;
        }
        prev = now;
    }
    
    void traverse(Node* root) {
        if (root == nullptr) {
            return;
        }
        traverse(root->left);
        addDoublyList(root->val);
        traverse(root->right);
    }

    Node* treeToDoublyList(Node* root) {
        prev = nullptr;
        head = nullptr;
        traverse(root);
        if (head) {
            head->left = prev;
            prev->right = head;
        }
        return head;
    }
};
