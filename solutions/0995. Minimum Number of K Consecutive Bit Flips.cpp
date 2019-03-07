class Solution {
public:
    int minKBitFlips(vector<int>& A, int k) {
        int n = A.size();
        int ans = 0;
        vector<int> sum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (i) {
                sum[i] += sum[i - 1];
            }
            int nowBit = (A[i] ^ (sum[i] % 2));
            if (nowBit == 0) {
                if (i + k > n) {
                    return -1;
                }
                ans++;
                sum[i + 1]++;
                sum[i + k]--;
            }
        }
        
        return ans;
    }
};
