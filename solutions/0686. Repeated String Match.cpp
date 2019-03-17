class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int lenA = A.size(), lenB = B.size();
        int ans = -1;
        for (int start = 0; start < lenA; start++) {
            bool flag = true;
            for (int i = 0; i < lenB; i++) {
                if (A[(start + i) % lenA] != B[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = (start + lenB) / lenA + ((start + lenB) % lenA != 0);
                break;
            }
        }
        
        return ans;
    }
};
