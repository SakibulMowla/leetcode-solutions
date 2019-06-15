class Solution {
public:
    int check(vector<int>& A, vector<int>& B, int x) {
        int n = A.size();
        int aCnt = 0, bCnt = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] != x && B[i] != x) {
                return numeric_limits<int>::max();
            }
            aCnt += A[i] != x;
            bCnt += B[i] != x;
        }
        return min(aCnt, bCnt);
    }
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int aAns = check(A, B, A[0]);
        int bAns = check(A, B, B[0]);

        return min(aAns, bAns) == numeric_limits<int>::max()
            ? -1
            : min(aAns, bAns);
    }
};
