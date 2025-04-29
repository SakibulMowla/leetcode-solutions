// Time - O(n * m)
// Memory - O(n + m)

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
    bool isExact(TreeNode* s, TreeNode* t) {
        if (s == nullptr || t == nullptr) {
            return s == nullptr && t == nullptr;
        }        
        return s->val == t->val && isExact(s->left, t->left) && isExact(s->right, t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr) return t == nullptr;
        return isExact(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t); 
    }
};

// -------------------------------------------------

// Time - O(n + m)
// Memory - O(n + m)

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
    string serialize(TreeNode* node) {
        if (node == nullptr) {
            return "#$";
        }
        return "#" + to_string(node->val) +
               serialize(node->left) +
               serialize(node->right);
    }
    
    vector<int> computeZ(const string& s) {
        vector<int> z(s.length());
        int l = 0, r = 0, n = s.length();
        
        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        
        return z;
    }


public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string serializedRoot = serialize(root);
        string serializedSubroot = serialize(subRoot);
        string combined = serializedSubroot + "|" + serializedRoot;

        vector<int> zScore = computeZ(combined);
        int subrootLen = serializedSubroot.size();

        for (int i = subrootLen + 1; i < combined.size(); i++) {
            if (zScore[i] == subrootLen) {
                return true;
            }
        }

        return false;
    }
};
