class Solution {
public:
    int countOdds(int low, int high) {
        int range = high - low + 1;
        int count = range / 2 + (range % 2 == 1 && low % 2 == 1);
        return count;
    }
};
