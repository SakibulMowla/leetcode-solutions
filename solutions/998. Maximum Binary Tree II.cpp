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
    TreeNode* findAndAdd(TreeNode* now, int val) {
        if (now == NULL) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        if (now->val > val) {
            now->right = findAndAdd(now->right, val);
            return now;
        } else {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = now;
            return newNode;
        }
    }
    
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        return findAndAdd(root, val);
    }
};
