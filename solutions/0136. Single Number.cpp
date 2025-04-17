class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < 32; i++) {
            int currentBit = (1 << i);
            bool flag = false;
            for (int num: nums) {
                int isSet = num & currentBit;
                if (isSet) {
                    flag = !flag;
                }
            }
            if (flag) {
                ans |= currentBit;
            }
        }

        return ans;
    }
};
