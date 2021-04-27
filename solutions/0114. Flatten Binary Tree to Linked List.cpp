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

class Solution {
private:
    TreeNode* dfs(TreeNode* root) {
        if (!root) {
            return nullptr;
        }        
        if (!root->left && !root->right) {
            return root;
        }
        
        TreeNode* leftRightMost = dfs(root->left);
        TreeNode* rightRightMost = dfs(root->right);
        
        if (leftRightMost) {
            leftRightMost->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        
        return rightRightMost ? rightRightMost : leftRightMost;
    }

public:
    void flatten(TreeNode* root) {
        dfs(root);
        return;
    }
};

// ----------------- Time Complexity - O(n) -----------------
// ----------------- Memory Complexity - O(1) -----------------

class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left) {
                TreeNode* rightMost = root->left;
                while (rightMost->right) {
                    rightMost = rightMost->right;
                }
                
                rightMost->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
        
        return;
    }
};
