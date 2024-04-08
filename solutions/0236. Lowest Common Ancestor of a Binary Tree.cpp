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
private:
    unordered_map<TreeNode*, TreeNode*> par;
    unordered_map<TreeNode*, int> height;

    void buildPar(TreeNode* root, int cur) {
        height[root] = cur;
        if (root->left) {
            par[root->left] = root;
            buildPar(root->left, cur + 1);
        }
        if (root->right) {
            par[root->right] = root;
            buildPar(root->right, cur + 1);
        }
        return;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        buildPar(root, 0);
        
        if (height[p] < height[q]) {
            swap(p, q);
        }
        
        while (height[p] > height[q]) {
            p = par[p];
        }
        
        if (p == q) {
            return p;
        }
        
        while (par[p] != par[q]) {
            p = par[p];
            q = par[q];
        }
        
        return par[p];
    }
};

// --------------------------------------------------

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
private:
    TreeNode* ans;
    
    bool traverse(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return false;
        }

        int leftCount = traverse(root->left, p, q) ? 1 : 0;
        int rightCount = traverse(root->right, p, q) ? 1 : 0;
        int midCount = (root == p || root == q) ? 1 : 0;

        if (leftCount + midCount + rightCount == 2) {
            ans = root;
        }

        return leftCount + midCount + rightCount > 0;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root, p, q);
        return ans;
    }
};
