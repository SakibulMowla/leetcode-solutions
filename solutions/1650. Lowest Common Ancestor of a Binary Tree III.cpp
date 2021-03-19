/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
  Node* lowestCommonAncestor(Node* p, Node * q) {
    Node* dupP = p;
    Node* dupQ = q;
    
    while (dupP or dupQ) {
      if (dupP && dupQ) {
        dupP = dupP->parent;
        dupQ = dupQ->parent;
      } else if (dupP) {
        dupP = dupP->parent;
        p = p->parent;
      } else {
        dupQ = dupQ->parent;
        q = q->parent;
      }
    }
    
    while (p != q) {
      p = p->parent;
      q = q->parent;
    }
    
    return p;
  }
};
