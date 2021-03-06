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
    void traverseAndBuildSet(TreeNode* root, unordered_set<int>& hash) {
        if (root == nullptr) {
            return;
        }        
        hash.insert(root->val);
        traverseAndBuildSet(root->left, hash);
        traverseAndBuildSet(root->right, hash);
        return;
    }
    
    bool traverseAndCheck(TreeNode* root, const unordered_set<int>& hash, int target) {
        if (root == nullptr) {
            return false;
        }
        if (hash.find(target - root->val) != hash.end()) {
            return true;
        }
        return traverseAndCheck(root->left, hash, target) || traverseAndCheck(root->right, hash, target);
    }

    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> hash;
        traverseAndBuildSet(root1, hash);
        return traverseAndCheck(root2, hash, target);
    }
};
