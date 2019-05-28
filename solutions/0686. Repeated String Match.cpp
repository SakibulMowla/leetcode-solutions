class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int aLen = A.size(), bLen = B.size();
        for (int i = 0; i < aLen; i++) {
            bool flag = true;
            for (int j = 0, k = i; j < bLen; j++, k++) {
                if (k == aLen) k = 0;
                if (B[j] != A[k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return (bLen + i) / aLen + bool((bLen + i) % aLen);
            }
        }
        return -1;
    }
};
