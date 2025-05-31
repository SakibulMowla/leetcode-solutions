class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            if ((n >> i) & 1) {
                ans |= 1;
            }
        }
        return ans;
    }
};

// ---------------------------------------------

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) | (n & 1);
            n >>= 1;
        }
        return ans;
    }
};

// ---------------------------------------------

// Memoization

class Solution {
private:
    int byte_size = 8;
    unordered_map<uint32_t, uint32_t> cache;

    uint32_t reverseByte(uint32_t n) {
        if (n == 0) {
            return 0;
        }
        if (cache.find(n) != cache.end()) {
            return cache[n];
        }

        int ans = 0;
        for (int i = 0; i < byte_size; i++) {
            ans = (ans << 1) | (n & 1);
            n >>= 1;
        }

        return cache[n] = ans;
    }    
public:
    uint32_t reverseBits(uint32_t n) {
        int mask = (1 << byte_size) - 1;
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            ans = (ans << byte_size) | reverseByte(n & mask);
            n >>= byte_size;
        }

        return ans;
    }
};
