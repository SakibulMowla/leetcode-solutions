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
    int distributeCoins(TreeNode* root, int& ans) {
        if (!root) return 0;
        int cal = root->val + distributeCoins(root->left, ans) + distributeCoins(root->right, ans) - 1;
        ans += abs(cal);
        return cal;
    }
    
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        distributeCoins(root, ans);
        return ans;
    }
};
