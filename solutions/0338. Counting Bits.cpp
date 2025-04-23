class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        bits[0] = 0;

        for (int i = 1, powOfTwo = 0; i <= n; i++) {
            // check for power of 2
            if ((i & (i - 1)) == 0) {
                powOfTwo = i;
            }
            bits[i] = 1 + bits[i - powOfTwo];
        }

        return bits;
    }
};
