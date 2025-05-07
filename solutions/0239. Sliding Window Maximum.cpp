// ==================================
// Time - O(N log K), Memory - O(N + K)
// ==================================

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> hash;
        int n = nums.size();
        for (int i = 0; i < k - 1; i++) {
            hash.insert(nums[i]);
        }
        
        vector<int> ans;
        for (int i = k - 1; i < n; i++) {
            hash.insert(nums[i]);
            ans.push_back(*prev(hash.end()));
            hash.erase(hash.lower_bound(nums[i - k + 1]));
        }
        
        return ans;
    }
};

// ==================================
// Monotonic Deque
// Time - O(N), Memory - O(N + K)
// ==================================

class Solution {
private:
    void addToDeque(deque<int>& dq, vector<int>& nums, int pos) {
        while (!dq.empty() && nums[dq.back()] <= nums[pos]) {
            dq.pop_back();
        }
        dq.push_back(pos);
        return;
    }
    
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;

        for (int i = 0; i < k - 1; i++) {
            addToDeque(dq, nums, i);
        }
        
        vector<int> ans;
        for (int i = k - 1; i < n; i++) {
            addToDeque(dq, nums, i);
            ans.push_back(nums[dq.front()]);
            if (dq.front() <= i - k + 1) {
                dq.pop_front();
            }
        }
        
        return ans;
    }
};

// ==================================
// Segment Tree
// Time - O(N log K), Memory - O(4 * N)
// ==================================

class SegmentTree {
private:
    int n;
    vector<int> tree;

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            tree[node] = nums[l];
        } else {
            int mid = l + (r - l) / 2;
            build(2 * node + 1, l, mid, nums);
            build(2 * node + 2, mid + 1, r, nums);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int l, int r, int start, int end) {
        if (r < start || l > end) {
            return INT_MIN;
        }

        if (start <= l && r <= end) {
            return tree[node];
        }

        int mid = l + (r - l) / 2;
        return max(query(2 * node + 1, l, mid, start, end), 
                   query(2 * node + 2, mid + 1, r, start, end));
    }


public:
    SegmentTree(int n, vector<int>& nums): n(n), tree(4 * n) {
        build(0, 0, n - 1, nums);
    }

    int query(int start, int end) {
        return query(0, 0, n - 1, start, end);
    }
};

class Solution {
private:

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int windowCount = n - k + 1;
        vector<int> ans(windowCount);
        
        SegmentTree segmenttree(n, nums);
        for (int i = 0; i < windowCount; i++) {
            ans[i] = segmenttree.query(i, i + k - 1);
        }

        return ans;
    }
};
