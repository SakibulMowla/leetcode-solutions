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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if (root) q.push({root, 0});
        
        vector<vector<int>> ans;
        int curLevel = -1;
        
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            
            TreeNode* cur = front.first;
            int level = front.second;
            
            if (level > curLevel) {
                curLevel = level;
                ans.push_back(vector<int> ());
            }
            
            ans[curLevel].push_back(cur->val);
            
            if (cur->left) {
                q.push({cur->left, level + 1});
            }
            
            if (cur->right) {
                q.push({cur->right, level + 1});
            }
        }
       
        return ans;
    }
};
