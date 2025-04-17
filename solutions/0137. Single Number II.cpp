class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int currentBit = 1;

        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int num: nums) {
                bool isSet = num & currentBit;
                if (isSet) {
                    count++;
                }
            }
            if (count % 3 == 1) {
                ans |= currentBit;
            }
            currentBit = currentBit << 1;
        }

        return ans;
    }
};
