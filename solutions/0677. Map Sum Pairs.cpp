class MapSum {
public:
    /** Initialize your data structure here. */
    
    struct Node {
        int sum;
        map<char, int> child;
        Node() {
            sum = 0;
            child.clear();
        }
    };
    
    vector<Node> trie;

    MapSum() {
        trie.push_back(Node());
    }
    
    void insert(string key, int val) {
        int root = 0;
        for (int i = 0; i < key.size(); i++) {
            if (trie[root].child.find(key[i]) == trie[root].child.end()) {
                trie[root].child[key[i]] = trie.size();
                trie.push_back(Node());
            }
            root = trie[root].child[key[i]];
        }
        trie[root].sum = val;
        return;
    }
    
    int dfs(int root) {
        int ans = trie[root].sum;
        for (auto it: trie[root].child) {
            ans += dfs(it.second);
        }
        return ans;
    }
    
    int sum(string prefix) {
        int root = 0;
        for (int i = 0; i < prefix.size(); i++) {
            if (trie[root].child.find(prefix[i]) == trie[root].child.end()) {
                return 0;
            }
            root = trie[root].child[prefix[i]];
        }
        return dfs(root);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
