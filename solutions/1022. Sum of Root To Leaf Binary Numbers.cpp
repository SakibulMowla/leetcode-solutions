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
    void traverse(TreeNode* root, int current, int& ans) {
        if (root == nullptr) {
            ;
        } else if (root->left == nullptr && root->right == nullptr) {
            ans += (current << 1) + root->val;
        } else {
            current = (current << 1) + root->val;
            traverse(root->left, current, ans);
            traverse(root->right, current, ans);   
        }
        return;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        traverse(root, 0, ans);
        return ans;
    }
};
