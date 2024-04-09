class Solution {
private:
    int n;
    vector<int> par;

    int findParent(int r) {
        return par[r] = r == par[r] ? r : findParent(par[r]);
    }

    void buildDisjointSet(vector<vector<string> >& accounts) {
        n = accounts.size();
        par = vector<int>(n);

        for (int i = 0; i < n; i++) {
            par[i] = i;
        }

        unordered_map<string, int> emailToIndex;
        int cur = 0;
        for (auto& account : accounts) {
            int sz = account.size();
            for (int i = 1; i < sz; i++) {
                if (emailToIndex.find(account[i]) == emailToIndex.end()) {
                    emailToIndex[account[i]] = cur;
                }
                else {
                    int x = findParent(cur);
                    int y = findParent(emailToIndex[account[i]]);
                    par[x] = y;
                }
            }
            cur++;
        }

        return;
    }

    void createMergedAccounts(vector<vector<string> >& accounts, unordered_map<int, set<string> >& mergedAccounts) {
        for (int i = 0; i < n; i++) {
            int now = findParent(i);
            for (int j = 1; j < accounts[i].size(); j++) {
                mergedAccounts[now].insert(accounts[i][j]);
            }
        }

        return;
    }

    vector<vector<string> > buildResultSet(vector<vector<string> >& accounts, unordered_map<int, set<string> >& mergedAccounts) {
        vector<vector<string> > ans;
        for (auto it : mergedAccounts) {
            vector<string> account;
            account.push_back(accounts[it.first][0]);
            for (auto email : it.second) {
                account.push_back(email);
            }
            ans.push_back(account);
        }

        return ans;
    }

public:
    vector<vector<string> > accountsMerge(vector<vector<string> >& accounts) {
        unordered_map<int, set<string> > mergedAccounts;

        buildDisjointSet(accounts);
        createMergedAccounts(accounts, mergedAccounts);
        return buildResultSet(accounts, mergedAccounts);
    }
};

// --------------------------------------------------------------------------

class Solution {
private:
    vector<int> parent, size;
    map<string, int> emailToParent;

    void initialize(int len) {
        parent = vector<int>(len);
        size = vector<int>(len);
        for (int i = 0; i < len; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        emailToParent.clear();
    }

    int findParent(int p) {
        if (p == parent[p]) {
            return p;
        }
        return parent[p] = findParent(parent[p]);
    }

    void _union(int a, int b) {
        a = findParent(a);
        b = findParent(b);

        if (a == b) {
            return;
        }

        if (size[a] <= size[b]) {
            size[b] += size[a];
            parent[a] = b;
        } else {
            size[a] += size[b];
            parent[b] = a;
        }

        return;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int len = accounts.size();
        initialize(len);

        for (int i = 0; i < accounts.size(); i++) {
            auto account = accounts[i];
            for (int j = 1; j < account.size(); j++) {
                if (!emailToParent.contains(account[j])) {
                    emailToParent[account[j]] = findParent(i);
                } else {
                    _union(emailToParent[account[j]], i);
                }
            }
        }

        unordered_map<int, int> parentToIndex;
        vector<vector<string>> ans;

        for (auto it: emailToParent) {
            int p = findParent(it.second);
            if (!parentToIndex.contains(p)) {
                int index = parentToIndex.size();
                parentToIndex[p] = index;
                ans.push_back(vector<string>());
                ans[index].push_back(accounts[p][0]);
            }
            ans[parentToIndex[p]].push_back(it.first);
        }

        return ans;
    }
};
