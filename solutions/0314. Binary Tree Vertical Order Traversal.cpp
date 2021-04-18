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

// =============== Time - O(n)   ==================
// =============== Memory - O(n) ==================

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        unordered_map<int, vector<int>> verticalMap;
        queue<pair<int, TreeNode*>> q;
        
        q.push({0, root});
        int minCol = 0;
        int maxCol = -1;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            
            if (!front.second) {
                continue;
            }
            
            int col = front.first;
            TreeNode* node = front.second;
            
            minCol = min(col, minCol);
            maxCol = max(col, maxCol);
            
            if (verticalMap.find(col) == verticalMap.end()) {
                verticalMap[col] = vector<int> ();
            }
            
            verticalMap[col].push_back(node->val);
            q.push({col - 1, node->left});
            q.push({col + 1, node->right});
        }
        
        vector<vector<int>> ans;
        for (int i = minCol; i <= maxCol; i++) {
            ans.push_back(verticalMap[i]);
        }
        
        return ans;
    }
};
