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

// Time - O(N)
// Space - O(N) recursive stack memory

class Solution {
private:
    int kth;

    void inorder(TreeNode* root, int& k) {
        if (k == 0) {
            return;
        }

        if (root == nullptr) {
            return;
        }

        inorder(root->left, k);
        k--;
        if (k == 0) {
            kth = root->val;
        }
        inorder(root->right, k);

        return;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return kth;
    }
};

// ------------------------------------------------------------------

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

// Time - O(N)
// Space - O(1)

class Solution {
private:
    // Morris traversal for inorder
    // https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
    int inOrder(TreeNode* root, int k) {
        TreeNode* cur = root;
        int count = 0, ans;

        while (cur != nullptr) {
            if (cur->left == nullptr) {
                count++;
                if (count == k) {
                    ans = cur->val;
                }
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                while (prev->right != nullptr && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = nullptr;
                    count++;
                    if (count == k) {
                        ans = cur->val;
                    }
                    cur = cur->right;
                }
            }
        }

        return ans;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        return inOrder(root, k);
    }
};
