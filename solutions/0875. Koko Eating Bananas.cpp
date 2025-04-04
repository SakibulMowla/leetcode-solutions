class Solution {
private:
    bool isPossible(vector<int>& piles, int k, int h) {
        long long hoursNeeded = 0;
        for (int pile: piles) {
            hoursNeeded += pile / k + (int)(pile % k != 0);
        }
        return hoursNeeded <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = 1E9, ans;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }

        return ans;
    }
};
