class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xOr = 0;
        for (int num: nums) {
            xOr ^= num;
        }

        int filterBit = 0;
        for (int i = 0; i < 32; i++) {
            if (xOr & (1 << i)) {
                filterBit = (1 << i);
                break;
            }
        }

        int a = 0, b = 0;
        for (int num: nums) {
            if (num & filterBit) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return {a, b};
    }
};
