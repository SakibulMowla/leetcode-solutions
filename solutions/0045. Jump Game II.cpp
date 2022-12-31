class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentJumpEnd = 0;
        int longest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            longest = max(longest, i + nums[i]);
            if (i == currentJumpEnd) {
                jumps++;
                currentJumpEnd = longest;
            }
        }
        
        return jumps;
    }
};
