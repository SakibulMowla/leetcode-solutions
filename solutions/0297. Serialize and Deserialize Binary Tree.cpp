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
public:
    void encode(TreeNode* root, string& str) {
        if (!root) {
            str += "null#";
        } else {
            str += to_string(root->val) + "#";
            encode(root->left, str);
            encode(root->right, str);
        }
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        encode(root, str);
        return str;
    }
    
    vector<string> parse(string encoded) {
        string cur;
        vector<string> ret;
        for (int i = 0; i < encoded.size(); i++) {
            if (encoded[i] == '#') {
                ret.push_back(cur);
                cur = "";
            } else {
                cur += encoded[i];
            }
        }
        return ret;
    }
    
    TreeNode* decode(vector<string>& parsed, int& pos) {
        TreeNode* now = NULL;
        string value = parsed[pos];
        pos++;

        if (value != "null") {
            now = new TreeNode(stoi(value));
            now->left = decode(parsed, pos);
            now->right = decode(parsed, pos);
        }
        
        return now;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> parsed = parse(data);
        int pos = 0;
        return decode(parsed, pos);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
