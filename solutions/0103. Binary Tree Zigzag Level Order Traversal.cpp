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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            
            if (front.second == ans.size()) {
                ans.push_back(vector<int>());
            }
            ans[front.second].push_back(front.first->val);
            
            if (front.first->left) {
                q.push({front.first->left, front.second + 1});
            }
            if (front.first->right) {
                q.push({front.first->right, front.second + 1});
            }
        }
        
        for (int i = 1; i < ans.size(); i += 2) {
            reverse(ans[i].begin(), ans[i].end());
        }
        
        return ans;
    }
};
