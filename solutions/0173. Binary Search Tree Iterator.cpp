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
class BSTIterator {
public:
    stack<TreeNode*> stk;

    BSTIterator(TreeNode* root) {
        leftTraverse(root);
    }
    
    void leftTraverse(TreeNode* root) {
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }
        return;
    }
    
    int next() {
        TreeNode* top = stk.top();
        stk.pop();
        leftTraverse(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return stk.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 
