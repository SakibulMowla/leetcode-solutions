/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void serialize(TreeNode* root, string& data) {
        if (!root) {
            data += "null|";
        } else {
            data += to_string(root->val) + '|';
            serialize(root->left, data);
            serialize(root->right, data);
        }
        return;
    }
    
    TreeNode* deserialize(int& pos, string& data) {
        string now;
        for (; data[pos] != '|'; pos++) {
            now += data[pos];
        }
        pos++;
        
        if (now == "null") {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(stoi(now));
        root->left = deserialize(pos, data);
        root->right = deserialize(pos, data);
        
        return root;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        serialize(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserialize(pos, data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
