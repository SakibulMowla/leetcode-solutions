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
    
    int findTilt(TreeNode* root, int& ans) {
        if (root == NULL) {
            return 0;
        } else {
            int sumL = findTilt(root->left, ans);
            int sumR = findTilt(root->right, ans);
            ans += abs(sumL - sumR);
            return root->val + sumL + sumR;
        } 
    }

    int findTilt(TreeNode* root) {
        int ans = 0;
        findTilt(root, ans);
        return ans;
    }
};
