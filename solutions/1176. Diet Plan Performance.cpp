class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size();
        int points = 0;
        vector<int> sum(n, 0);

        for (int i = 0; i < calories.size(); i++) {
            sum[i] = calories[i] + (i ? sum[i - 1] : 0);
            if (i >= k - 1) {
                int T = sum[i] - (i - k >= 0 ? sum[i - k] : 0);
                if (T < lower) {
                    points--;
                } else if (T > upper) {
                    points++;
                }
            }
        }
        
        return points;
    }
};
