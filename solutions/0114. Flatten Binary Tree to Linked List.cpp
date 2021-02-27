// ----------------- Time Complexity - O(n) -----------------
// ----------------- Memory Complexity - O(n) -----------------

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
    void traverse(TreeNode* root, stack<TreeNode*>& stk) {
        if (root == nullptr) {
            return;
        }
        stk.push(root);
        traverse(root->left, stk);
        traverse(root->right, stk);
        return;
    }
    
    void flatten(TreeNode* root) {
        stack<TreeNode*> stk;
        traverse(root, stk);
        TreeNode* last = nullptr;
        while (!stk.empty()) {
            TreeNode* top = stk.top();
            stk.pop();
            top->right = last;
            top->left = nullptr;
            last = top;
        }
        return;
    }
};

// ----------------- Time Complexity - O(n) -----------------
// ----------------- Memory Complexity - O(1) (exclusing recursion stack) -----------------

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
    TreeNode* dfs(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        TreeNode* leftHalf = dfs(root->left);
        TreeNode* rightHalf = dfs(root->right);
        if (leftHalf) {
            TreeNode* tmp = leftHalf;
            while (tmp->right) {
                tmp = tmp->right;
            }
            tmp->right = rightHalf;
            root->right = leftHalf;
        } else {
            root->right = rightHalf;
        }
        root->left = nullptr;
        return root;
    }

    void flatten(TreeNode* root) {
        root = dfs(root);
        return;
    }
};
