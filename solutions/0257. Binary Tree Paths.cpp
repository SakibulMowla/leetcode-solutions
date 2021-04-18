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
    void traverse(TreeNode* root, string cur, vector<string>& ans) {
        if (!root->left && !root->right) {
            ans.push_back(cur + to_string(root->val));
        } else {
            string next = cur + to_string(root->val) + "->";
            if (root->left) traverse(root->left, next, ans);
            if (root->right) traverse(root->right, next, ans);
        }
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string cur = "";
        vector<string> ans;
        traverse(root, cur, ans);
        return ans;
    }
};
