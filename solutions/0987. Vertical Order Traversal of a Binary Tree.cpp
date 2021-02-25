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
    void dfs(TreeNode* root, int col, int row, map<int, vector<pair<int, int>>>& store) {
        if (root == nullptr) {
            return;
        }
        store[col].push_back({row, root->val});
        dfs(root->left, col - 1, row + 1, store);
        dfs(root->right, col + 1, row + 1, store);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> store;
        dfs(root, 0, 0, store);
        vector<vector<int>> ans;
        for (auto it: store) {
            vector<int> tmp;
            sort(it.second.begin(), it.second.end());
            for (auto x: it.second) {
                tmp.push_back(x.second);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
