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

    int longestUnivaluePath(TreeNode* now, int& ans) {
        if (!now) {
            return 0;
        } else {
            int ansL = longestUnivaluePath(now->left, ans);
            int ansR = longestUnivaluePath(now->right, ans);
            int sameL = 0, sameR = 0;
            if (now->left && now->left->val == now->val) {
                sameL = 1 + ansL;
            }
            if (now->right && now->right->val == now->val) {
                sameR = 1 + ansR;
            }
            ans = max(ans, sameL + sameR);
            return max(sameL, sameR);
        }
    }

    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        longestUnivaluePath(root, ans);
        return ans;
    }
};
