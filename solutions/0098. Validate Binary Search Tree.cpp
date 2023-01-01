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
    bool isValidBST(TreeNode* root, TreeNode* minimum = nullptr, TreeNode* maximum = nullptr) {
        if (!root) {
            return true;
        }
        if (maximum && root->val >= maximum->val) {
            return false;
        }
        if (minimum && root->val <= minimum->val) {
            return false;
        }
        return isValidBST(root->left, minimum, root) &&
            isValidBST(root->right, root, maximum);
    }
};
