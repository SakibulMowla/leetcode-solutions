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
    int getLeftHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->left;
        }
        return height;
    }
    
    int getRightHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
