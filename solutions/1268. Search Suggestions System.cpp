// Trie

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

// ------------------------------------------------------------------

// Binary Search

class Solution {
private:
    bool containsFromBegin(string& word, string& prefix) {
        if (word.size() < prefix.size()) {
            return false;
        }

        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] != word[i]) {
                return false;
            }
        }

        return true;
    }

    int findIndex(vector<string>& words, string& prefix, int lo, int hi) {
        int index = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (words[mid] < prefix) {
                lo = mid + 1;
            } else {
                index = mid;
                hi = mid - 1;
            }
        }

        return index;
    }

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        sort(products.begin(), products.end());

        int len = searchWord.size();
        vector<vector<string>> ans(len);

        string prefix = "";
        int lo = 0;
        for (int i = 0; i < len; i++) {
            prefix += searchWord[i];
            int index = findIndex(products, prefix, lo, n - 1);

            // binary search
            if (index == -1) {
                continue;
            }

            lo = index;

            for (int k = 0; k < 3 && index + k < n; k++) {
                string& word = products[index + k];
                if (containsFromBegin(word, prefix)) {
                    ans[i].push_back(word);
                }
            }
        }      

        return ans;
    }
};
