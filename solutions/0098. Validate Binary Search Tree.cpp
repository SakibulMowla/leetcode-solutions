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
    bool isValidBST(TreeNode* root,
        long long mn = numeric_limits<int>::min(),
        long long mx = numeric_limits<int>::max()) {
        if (root == nullptr) {
            return true;
        }
        if (root->val < mn || root->val > mx) {
            return false;
        }
        return isValidBST(root->left, mn, root->val - 1LL) &&
            isValidBST(root->right, root->val + 1LL, mx);
    }
};
