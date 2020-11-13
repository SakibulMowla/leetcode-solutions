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
    int dfs(TreeNode* root, int& best) {
        if (root == nullptr) {
            return 0;
        }

        int leftTreeMax = max(0, dfs(root->left, best));
        int rightTreeMax = max(0, dfs(root->right, best));

        best = max(best, root->val + leftTreeMax + rightTreeMax);
        int ans = root->val + max(leftTreeMax, rightTreeMax);

        return ans;
    }

    int maxPathSum(TreeNode* root) {
        int best = numeric_limits<int>::min();
        dfs(root, best);
        return best;
    }
};

/*
Inputs:
[1,2,3]
[-10,9,20,null,null,15,7]
[-1,-2,3,null,null,-4,-5]
[-3]

Outputs:
6
42
3
-3
*/
