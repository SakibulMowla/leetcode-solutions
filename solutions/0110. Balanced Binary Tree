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
private:
    int findDepth(TreeNode* root, bool& ans) {
        if (root == nullptr) {
            return 0;
        }
        int lDepth = findDepth(root->left, ans);
        int rDepth = findDepth(root->right, ans);
        if (abs(lDepth - rDepth) > 1) {
            ans = false;
        }
        return 1 + max(lDepth, rDepth);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        findDepth(root, ans);
        return ans;
    }
};
