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
    void traverse(TreeNode* root, int level, vector<int>& rightNodes) {
        if (root == nullptr) {
            return;
        }
        
        if (level == rightNodes.size()) {
            rightNodes.push_back(0);
        }

        rightNodes[level] = root->val;

        traverse(root->left, level + 1, rightNodes);
        traverse(root->right, level + 1, rightNodes);

        return;
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightNodes;
        traverse(root, 0, rightNodes);
        return rightNodes;
    }
};

// ----------------------------------------------------------------------

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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        vector<int> ans;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            if (front.first == nullptr) {
                continue;
            }

            if (front.second == ans.size()) {
                ans.push_back(0);
            }

            ans[front.second] = front.first->val;

            q.push({front.first->left, 1 + front.second});
            q.push({front.first->right, 1 + front.second});
        }

        return ans;
    }
};
