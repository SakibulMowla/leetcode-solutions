class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> ways(amount + 1, 0);
        ways[0] = 1;
        
        for (int coin: coins) {
            for (int val = coin; val <= amount; val++) {
                ways[val] += ways[val - coin];
            }
        }
        
        return ways[amount];
    }
};
