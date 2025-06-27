// Hashset

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        for (int num: arr1) {
            while (num && !prefixes.contains(num)) {
                prefixes.insert(num);
                num /= 10;
            }
        }

        int ans = 0;
        for (int num: arr2) {
            while (num) {
                if (prefixes.contains(num)) {
                    ans = max(ans, (int)to_string(num).size());
                    break;
                }
                num /= 10;
            }
        }

        return ans;
    }
};

// Trie

struct Trie {
    unordered_map<char, int> child;
};

class Solution {
private:
    vector<Trie> tree;

    void insert(int num) {
        string word = to_string(num);
        int node = 0;
        for (char ch: word) {
            if (!tree[node].child.contains(ch)) {
                tree[node].child[ch] = tree.size();
                tree.push_back(Trie());
            }
            node = tree[node].child[ch];
        }
        return;
    }

    int query(int num) {
        string word = to_string(num);
        int node = 0, prefix = 0;
        for (char ch: word) {
            if (!tree[node].child.contains(ch)) {
                break;
            }
            prefix++;
            node = tree[node].child[ch];
        }

        return prefix;
    }

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        tree.push_back(Trie()); // root

        for (int num: arr1) 
            insert(num);

        int ans = 0;
        for (int num: arr2) 
            ans = max(ans, query(num));

        return ans;
    }
};
