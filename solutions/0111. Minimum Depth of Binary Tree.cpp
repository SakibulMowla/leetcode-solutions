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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int minVal = numeric_limits<int>::max();
        if (root->left) {
            minVal = minDepth(root->left);
        }
        if (root->right) {
            minVal = min(minVal, minDepth(root->right));
        }
        return 1 + (minVal == numeric_limits<int>::max() ? 0 : minVal);
    }
};
