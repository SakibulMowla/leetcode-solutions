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
    void dfs(TreeNode* root, int& best, double target) {
        if (!root) {
            return;
        }        
        
        if (abs(root->val - target) < abs(best - target)) {
            best = root->val;
        }
        
        if (target < root->val) {
            dfs(root->left, best, target);
        } else {
            dfs(root->right, best, target);
        }
        
        return;
    }

public:
    int closestValue(TreeNode* root, double target) {
        if (!root) {
            return -1;
        }
        
        int best = root->val;
        dfs(root, best, target);
        
        return best;
    }
};
