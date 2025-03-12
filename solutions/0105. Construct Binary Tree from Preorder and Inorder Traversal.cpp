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
private:
    unordered_map<int, int> inorderIndex;
    int preorderIndex;

    TreeNode* traverse(int left, int right, vector<int>& preorder) {
        if (left > right) {
            return nullptr;
        }

        int val = preorder[preorderIndex++];
        TreeNode* cur = new TreeNode(val);

        int mid = inorderIndex[val];
        cur->left = traverse(left, mid - 1, preorder);
        cur->right = traverse(mid + 1, right, preorder);

        return cur;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        
        for (int i = 0; i < n; i++) {
            inorderIndex[inorder[i]] = i;
        }
        preorderIndex = 0;

        return traverse(0, n - 1, preorder);
    }
};
