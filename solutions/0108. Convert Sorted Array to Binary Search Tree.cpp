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
    TreeNode* traverse(vector<int>& nums, int start, int end) {
        if (end < start) {
            return nullptr;
        }
        if (start == end) {
            return new TreeNode(nums[start]);
        }

        int mid = (start + end) / 2;

        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = traverse(nums, start, mid - 1);
        cur->right = traverse(nums, mid + 1, end);

        return cur;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traverse(nums, 0, nums.size() - 1);
    }
};
