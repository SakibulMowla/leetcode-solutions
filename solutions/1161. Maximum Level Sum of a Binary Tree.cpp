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

----------------------------------------------------
// DFS
----------------------------------------------------

class Solution {
public:
    
    void dfs(TreeNode* root, int level, map<int, int>& hash) {
        if (root == nullptr) {
            return;
        }
        
        if (hash.find(level) == hash.end()) {
            hash[level] = 0;
        }
        hash[level] += root->val;
        
        dfs(root->left, level + 1, hash);
        dfs(root->right, level + 1, hash);
        
        return;
    }
    
    int maxLevelSum(TreeNode* root) {
        map<int, int> hash;
        dfs(root, 1, hash);
        
        int ans;
        int best = numeric_limits<int>::min();
        for (auto it: hash) {
            if (it.second > best) {
                best = it.second;
                ans = it.first;
            }
        }
        
        return ans;
    }
};

----------------------------------------------------
// BFS
----------------------------------------------------

class Solution {
public:
    
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> fifo;
        fifo.push(root);
        
        int level = 0;
        int ans = 0;
        int best = numeric_limits<int>::min();
        
        while (!fifo.empty()) {
            int limit = fifo.size();
            level++;
            
            int sum = 0;
            for (int i = 0; i < limit; i++) {
                TreeNode* now = fifo.front();
                fifo.pop();
                
                sum += now->val;
                if (now->left) fifo.push(now->left);
                if (now->right) fifo.push(now->right);
            }
            
            if (sum > best) {
                best = sum;
                ans = level;
            }
        }
        
        return ans;
    }
};
