class Solution {
public:
    bool isPerfectSquare(int num) {
        int lo = 1, hi = num;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid == num / mid && num % mid == 0) {
                return true;
            } else if (mid > 1.0 * num / mid) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return false;
    }
};
