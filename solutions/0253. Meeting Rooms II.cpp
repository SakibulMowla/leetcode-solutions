// =============== Priority Queue ===============

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int ans = 0, qsz = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto interval: intervals) {
            while (!pq.empty() && pq.top() <= interval[0]) {
                pq.pop();
                qsz--;
            }
            pq.push(interval[1]);
            qsz++;
            ans = max(ans, qsz);
        }

        return ans;
    }
};

// =============== Point Compression ===============

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        set<int> points;

        for (auto& interval: intervals) {
            points.insert(interval[0]);
            points.insert(interval[1]);
        }
        
        unordered_map<int, int> rank;
        int total = 0;
        
        for (auto it: points) {
            rank[it] = total++; 
        }
        
        vector<int> cnt(total, 0);
        
        for (auto& interval: intervals) {
            cnt[rank[interval[0]]]++;
            cnt[rank[interval[1]]]--;
        }
        
        int ans = 0;
        for (int i = 0; i < total; i++) {
            if (i) {
                cnt[i] += cnt[i - 1];
            }
            ans = max(ans, cnt[i]);
        }
        
        return ans;
    }
};
