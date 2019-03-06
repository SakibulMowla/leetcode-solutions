/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        if (root == NULL) {
            return "";
        } else {
            string leftStr = smallestFromLeaf(root->left);
            string rightStr = smallestFromLeaf(root->right);
            if (leftStr == "" || rightStr == "") {
                return max(leftStr, rightStr) + (char)('a' + root->val);
            } else {
                return min(leftStr, rightStr) + (char)('a' + root->val);   
            }
        }
    }
};
