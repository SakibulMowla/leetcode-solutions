// ==============================================
// O(3 * (n - 1))
// ==============================================

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
private:
    int isCelebrity(int candidate, int n) {
        for (int i = 0; i < n; i++) {
            if (i == candidate) {
                continue;
            }
            if (!knows(i, candidate) || knows(candidate, i)) {
                return false;
            }
        }
        return true;
    }

public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }
        return isCelebrity(candidate, n) ? candidate : -1;
    }
};
