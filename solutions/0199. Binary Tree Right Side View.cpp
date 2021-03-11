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
    struct Data {
        TreeNode* node;
        int height;
        Data(TreeNode* node, int height): node(node), height(height) {}
    };
    
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<Data> q;
        if (root) {
            q.push(Data(root, 0));
        }

        vector<int> ans;
        
        while (!q.empty()) {
            Data front = q.front();
            q.pop();
            
            if (ans.size() == front.height) {
                ans.push_back(front.node->val);
            } else {
                ans[front.height] = front.node->val;
            }
            
            if (front.node->left) {
                q.push(Data(front.node->left, front.height + 1));
            }
            if (front.node->right) {
                q.push(Data(front.node->right, front.height + 1));
            }
        }
        
        return ans;
    }
};
