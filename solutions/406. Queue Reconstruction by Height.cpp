// O(n^2)
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> ans;
        
        int n = people.size();
        vector<int> degree(n, 0);

        sort(people.begin(), people.end());
        
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++) {
            if (people[i].second == degree[i]) {
                q.push(i);
            }            
        }
        
        while(!q.empty()) {
            int u = q.top();
            q.pop();
            ans.push_back(people[u]);
            for (int i = 0; i < n; i++) {
                if (people[u].first >= people[i].first) {
                    degree[i]++;
                    if (degree[i] == people[i].second) {
                        q.push(i);
                    }
                }
            }
        }
        
        return ans;
    }
};


// O(nlogn)
class Solution {
public:
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        return a.first == b.first ? 
               a.second < b.second :
               a.first > b.first;
    }

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), comp);
        
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            ans.insert(ans.begin() + people[i].second, people[i]);
        }
        
        return ans;
    }
};
