
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
    
    void traverse(TreeNode* now, int x, int y, map<int, vector<pair<int, int>>>& hash) {
        if (now != NULL) {
            if (hash.find(x) == hash.end()) {
                hash[x] = vector<pair<int, int>>();
            }
            hash[x].push_back({y, now->val});
            traverse(now->left, x - 1, y - 1, hash);
            traverse(now->right, x + 1, y - 1, hash);
        }
        return;
    }
    
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
    
    vector<int> sortVertical(vector<pair<int, int>>& line) {
        sort(line.begin(), line.end(), comp);
        vector<int> res;
        for (auto val: line) {
            res.push_back(val.second);
        }
        return res;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> hash;
        traverse(root, 0, 0, hash);
        
        vector<vector<int>> ans;
        for (auto& it: hash) {
            ans.push_back(sortVertical(it.second));
        }

        return ans;
    }
};
