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
    void inorder(TreeNode* root, vector<int>& sortedList) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, sortedList);
        sortedList.push_back(root->val);
        inorder(root->right, sortedList);
        return;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> sortedList;
        inorder(root, sortedList);
        
        int l = 0, r = int(sortedList.size()) - 1;
        bool ans = false;

        while (l < r) {
            int sum = sortedList[l] + sortedList[r];
            if (sum == k) {
                ans = true;
                break;
            } else if (sum > k) {
                r--;
            } else {
                l++;
            }
        }
        
        return ans;
    }
};
