class Solution {
public:
    int countPrimes(int n) {
        int cnt = (n > 2);
        vector<int> mark(n, true);
        for (int i = 3; i < n; i += 2) {
            if (mark[i]) {
                cnt++;
                for (int j = 3 * i; j < n; j += 2 * i) {
                    mark[j] = false;
                }
            }
        }
        return cnt;
    }
};
