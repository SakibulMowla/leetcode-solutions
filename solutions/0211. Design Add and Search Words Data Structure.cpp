class WordDictionary {
public:
    /** Initialize your data structure here. */
    
    struct Trie {
        bool isEnd;
        map<char, int> next;
        Trie() {
            isEnd = false;
        }
    };
    
    vector<Trie> tree;
    
    WordDictionary() {
        tree.push_back(Trie());
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int node = 0;
        for (char ch: word) {
            if (tree[node].next.find(ch) == tree[node].next.end()) {
                tree.push_back(Trie());
                tree[node].next[ch] = tree.size() - 1;
            }
            node = tree[node].next[ch];
        }
        tree[node].isEnd = true;
        return;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word, 0, 0);
    }
    
    bool dfs(string& word, int pos, int node) {
        if (pos == word.size()) {
            return tree[node].isEnd;
        } else {
            bool ret = false;
            if (word[pos] == '.') {
                for (auto it: tree[node].next) {
                    ret |= dfs(word, pos + 1, it.second);
                    if (ret) {
                        break;
                    }
                }
            } else {
                ret = tree[node].next.find(word[pos]) == tree[node].next.end() ?
                    false :
                    dfs(word, pos + 1, tree[node].next[word[pos]]);
            }
            return ret;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
