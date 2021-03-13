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
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        int tmp = ans;
        if (target > root->val && root->right) {
            tmp = closestValue(root->right, target);
        } else if (target < root->val && root->left) {
            tmp = closestValue(root->left, target); 
        }
        if (abs(target - tmp) < abs(target - ans)) {
            ans = tmp;
        }
        return ans;
    }
};
