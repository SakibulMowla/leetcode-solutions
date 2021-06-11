class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        
        int ans = sum;
        for (int i = k - 1, j = n - 1; i >= 0; i--, j--) {
            sum -= cardPoints[i];
            sum += cardPoints[j];
            ans = max(ans, sum);
        }
        
        return ans;
    }
};
