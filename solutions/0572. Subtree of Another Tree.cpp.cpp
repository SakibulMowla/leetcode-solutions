/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isExact(TreeNode* s, TreeNode* t) {
        if (s == nullptr || t == nullptr) {
            return s == nullptr && t == nullptr;
        }        
        return s->val == t->val && isExact(s->left, t->left) && isExact(s->right, t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr) return t == nullptr;
        return isExact(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t); 
    }
};
