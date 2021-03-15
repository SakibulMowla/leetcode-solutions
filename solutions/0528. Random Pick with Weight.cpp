class Solution {
public:
    int n;
    vector<int> sum;

    Solution(vector<int>& w) {    
        n = w.size();
        sum = vector<int>(n);
        
        for (int i = 0; i < n; i++) {
            sum[i] = w[i] + (i ? sum[i - 1] : 0);
        }
    }
    
    int pickIndex() {
        int val = (rand() % sum[n - 1]) + 1;
        
        int lo = 0;
        int hi = n;
        int index;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (val > sum[mid]) {
                lo = mid + 1;
            } else {
                index = mid;
                hi = mid - 1;
            }
        }
        
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
