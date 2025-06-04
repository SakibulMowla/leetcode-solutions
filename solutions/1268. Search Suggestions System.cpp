class TrieNode {
public:
    bool isWord;
    map<char, int> child;

    TrieNode(): isWord(false) {}
};

class Solution {
private:
    vector<TrieNode> tree;

    void insert(string& product) {
        int node = 0;
        for (char ch: product) {
            if (tree[node].child.find(ch) == tree[node].child.end()) {
                tree[node].child[ch] = tree.size();
                tree.push_back(TrieNode());
            }
            node = tree[node].child[ch];
        }
        tree[node].isWord = true;

        return;
    }

    void dfs(int node, vector<string>& suggestion, string& current) {
        if (suggestion.size() == 3) {
            return;
        }

        if (tree[node].isWord) {
            suggestion.push_back(current);
        }

        for (auto it: tree[node].child) {
            current.push_back(it.first);
            dfs(it.second, suggestion, current);
            current.pop_back();
        }

        return;
    }

    void traverse(string& searchWord, vector<vector<string>>& ans) {
        int node = 0, index = 0;
        string current = "";
        for (char ch: searchWord) {
            if (tree[node].child.find(ch) == tree[node].child.end()) {
                break;
            }

            node = tree[node].child[ch];
            current += ch;
            
            vector<string> suggestion;
            dfs(node, suggestion, current);

            ans[index++] = suggestion;
        }

        return;
    }

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // insert root
        tree.push_back(TrieNode());

        for (string& product: products) {
            insert(product);
        }

        int len = searchWord.size();
        vector<vector<string>> ans(len);

        traverse(searchWord, ans);

        return ans;
    }
};
