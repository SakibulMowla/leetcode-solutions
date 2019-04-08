class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> rclosest(n);

        int last = n + n;
        for (int i = n - 1; i >= 0; i--) {
            if (seats[i] == 1) 
                last = i;
            rclosest[i] = last;
        }
        
        int ans = 0;
        last = -n;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1)
                last = i;
            if (seats[i] == 0)
                ans = max(min(i - last, rclosest[i] - i), ans);
        }
        
        return ans;
    }
};

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        
        int cnt = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (seats[i] == 0) {
                cnt++;
                ans = max(ans, (cnt + 1) / 2);
            } else {
                cnt = 0;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                ans = max(ans, i);
                break;
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (seats[i] == 1) {
                ans = max(ans, n - 1 - i);
                break;
            }
        }
        
        return ans;
    }
};

