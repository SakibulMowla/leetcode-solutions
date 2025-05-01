class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        vector<int> queriesSorted = queries;
        sort(queriesSorted.begin(), queriesSorted.end());

        int index = 0, n = intervals.size();
        priority_queue<pair<int, int>> sizeAndEnd;
        unordered_map<int, int> res;

        for (int q: queriesSorted) {
            while (index < n && intervals[index][0] <= q) {
                int l = intervals[index][0], r = intervals[index][1];
                sizeAndEnd.push({-(r - l + 1), r});
                index++;
            }

            while (!sizeAndEnd.empty() && sizeAndEnd.top().second < q) {
                sizeAndEnd.pop();
            }

            res[q] = sizeAndEnd.empty() ? -1 : -sizeAndEnd.top().first;
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = res[queries[i]];
        }

        return ans;
    }
};

// ------------------------------------------------------------------------


class SegmentTree {
private:
    std::vector<int> tree, lazy;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = INT_MAX;     // Default value
            lazy[node] = INT_MAX;
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = INT_MAX;
            lazy[node] = INT_MAX;
        }
    }

    void propagate(int node, int start, int end) {
        if (lazy[node] != INT_MAX) {
            tree[node] = std::min(tree[node], lazy[node]);
            if (start != end) {
                lazy[2 * node] = std::min(lazy[2 * node], lazy[node]);
                lazy[2 * node + 1] = std::min(lazy[2 * node + 1], lazy[node]);
            }
            lazy[node] = INT_MAX;
        }
    }

    void rangeUpdate(int node, int start, int end, int l, int r, int val) {
        propagate(node, start, end);
        if (r < start || end < l) return;

        if (l <= start && end <= r) {
            lazy[node] = std::min(lazy[node], val);
            propagate(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        rangeUpdate(2 * node, start, mid, l, r, val);
        rangeUpdate(2 * node + 1, mid + 1, end, l, r, val);
    }

    int pointQuery(int node, int start, int end, int idx) {
        propagate(node, start, end);
        if (start == end) return tree[node];

        int mid = (start + end) / 2;
        if (idx <= mid)
            return pointQuery(2 * node, start, mid, idx);
        else
            return pointQuery(2 * node + 1, mid + 1, end, idx);
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, INT_MAX);
        lazy.resize(4 * n, INT_MAX);
        build(1, 0, n - 1);
    }

    void update(int l, int r, int val) {
        rangeUpdate(1, 0, n - 1, l, r, val);
    }

    int get(int idx) {
        return pointQuery(1, 0, n - 1, idx);
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> uniques;
        for (auto& interval: intervals) {
            uniques.push_back(interval[0]);
            uniques.push_back(interval[1]);
        }

        for (int q: queries) {
            uniques.push_back(q);
        }

        sort(uniques.begin(), uniques.end());
        uniques.erase(unique(uniques.begin(), uniques.end()), uniques.end());

        int n = uniques.size();
        unordered_map<int, int> compress;

        for (int i = 0; i < n; i++) {
            compress[uniques[i]] = i;
        }

        SegmentTree seg(n); // values are implicitly INT_MAX

        for (auto& interval: intervals) {
            int l = compress[interval[0]];
            int r = compress[interval[1]];
            seg.update(l, r, interval[1] - interval[0] + 1);
        }

        vector<int> ans;
        for (int q: queries) {
            int val = seg.get(compress[q]);
            ans.push_back(val == INT_MAX ? -1 : val);
        }

        return ans;
    }
};
