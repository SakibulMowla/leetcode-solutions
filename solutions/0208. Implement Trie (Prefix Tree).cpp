class Trie {
private:
    struct Node {
        bool isEnd;
        unordered_map<char, int> child;
        Node() {
            isEnd = false;
        }
    };
    
    vector<Node> tree;

public:
    Trie() {
        tree.clear();
        tree.push_back(Node());   
    }
    
    void insert(string word) {
        int node = 0;
        for (char ch: word) {
            if (tree[node].child.find(ch) == tree[node].child.end()) {
                tree[node].child[ch] = tree.size();
                tree.push_back(Node());
            }
            node = tree[node].child[ch];
        }
        tree[node].isEnd = true;
    }
    
    bool search(string word) {
        int node = 0;
        for (char ch: word) {
            if (tree[node].child.find(ch) == tree[node].child.end()) {
                return false;
            }
            node = tree[node].child[ch];
        }
        return tree[node].isEnd;
    }
    
    bool startsWith(string prefix) {
        int node = 0;
        for (char ch: prefix) {
            if (tree[node].child.find(ch) == tree[node].child.end()) {
                return false;
            }
            node = tree[node].child[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
