class Solution {
public:

    struct Trie {
        int link[2];
        Trie() {
            memset(link, -1, sizeof link);
        }
    };

    int findMax(vector<Trie>& tree, int n) {
        int now = 0;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (tree[now].link[bit ^ 1] == -1) {
                ans = (ans << 1);
                now = tree[now].link[bit];
            } else {
	            ans = (ans << 1) | 1;
                now = tree[now].link[bit ^ 1];
            }
        }

        return ans;
    }

    void add(vector<Trie>& tree, int n) {
        int now = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (tree[now].link[bit] == -1) {
                tree[now].link[bit] = tree.size();
                tree.push_back(Trie());
            }
            now = tree[now].link[bit];
        }

        return;
    }

    int findMaximumXOR(vector<int>& nums) {
        vector<Trie> tree;
        tree.push_back(Trie());

        int ans = 0;
        for (auto num: nums) {
            if (tree.size() > 1) ans = max(ans, findMax(tree, num));
            add(tree, num);
        }

        return ans;
    }
};

