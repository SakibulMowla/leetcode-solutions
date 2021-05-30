// =========================================
// Time - O(1), Memory - O(1)
// =========================================

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int oneBits = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                oneBits++;
            }
        }
        return oneBits;
    }
};

// =========================================
// Time - O(1), Memory - O(1)
// =========================================

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int oneBits = 0;
        while (n) {
            oneBits++;
            n &= (n - 1);
        }
        return oneBits;
    }
};
