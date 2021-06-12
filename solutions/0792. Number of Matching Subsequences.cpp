class Solution {
private:
    struct Trie {
        int ends;
        unordered_map<char, int> child;        
        char ch;
        Trie() {
            ends = 0;
        }
    };

    void insert(string& word, vector<Trie>& tree) {
        int node = 0;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (tree[node].child.find(ch) == tree[node].child.end()) {
                tree[node].child[ch] = tree.size();                
                tree.push_back(Trie());
            }
            node = tree[node].child[ch];
            tree[node].ch = ch;
        }
        tree[node].ends++;
        return;
    }

    int findSubSequence(int pos, int node, string& word, vector<Trie>& tree, vector<vector<int>>& occur) {
        int ret = tree[node].ends;

        if (pos == word.size()) {
            return ret;
        }

        for (auto it: tree[node].child) {
            auto index = lower_bound(occur[it.first - 'a'].begin(), occur[it.first - 'a'].end(), pos);
            if (index != occur[it.first - 'a'].end()) {
                ret += findSubSequence(*index + 1, it.second, word, tree, occur);
            }
        }

        return ret;
    }

public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<Trie> tree;
        tree.push_back(Trie());
        
        vector<vector<int>> occur(26, vector<int>());
        for (int i = 0; i< s.size(); i++) {
            occur[s[i] - 'a'].push_back(i);
        }

        for (string word: words) {
            insert(word, tree);
        }
    
        return findSubSequence(0, 0, s, tree, occur);
    }
};

// =================================================================

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> occur(26, vector<int>());
        for (int i = 0; i< s.size(); i++) {
            occur[s[i] - 'a'].push_back(i);
        }

        int cnt = 0;
        for (string word: words) {
            bool flag = true;
            for (int i = 0, pos = 0; i < word.size(); i++) {
                int index = word[i] - 'a';
                auto it = lower_bound(occur[index].begin(), occur[index].end(), pos);
                if (it != occur[index].end()) {
                    pos = *it + 1;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cnt++;
            }
        }
    
        return cnt;
    }
};
