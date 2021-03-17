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
