// ===============================================
// Time - O(n * m) Space - O(1)
// ===============================================

class Solution {
public:
    bool presentFrom(int buffer, string& haystack, string& needle) {
        for (int i = 0; i < needle.size(); i++) {
            if (needle[i] != haystack[buffer + i]) {
                return false;
            }
        }
        return true;
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i + m -1 < n; i++) {
            if (presentFrom(i, haystack, needle)) {
                return i;
            }
        }
        
        return -1;
    }
};

// ===============================================
// Rabin–Karp Algorithm Rolling Hash
// Time - O(n + m) Space - O(1)
// ===============================================

class Solution {
private:
    using ll = long long;
    const ll mod = 1E9 + 7;

    ll calcHash(string s) {
        int n = s.size();
        ll base = 1;
        ll hash = 0;
        for (int i = 0; i < n; i++) {
            hash = (hash + ((s[i] - 'a') * base) % mod) % mod;
            base = (base * 26) % mod;
        }
        return hash;
    }

    ll _power(ll b, ll p) {
        if (p == 0) {
            return 1;
        }
        ll ret = _power(b, p / 2);
        ret = (ret * ret) % mod;
        if (p % 2 == 1) {
            ret = (ret * b) % mod;
        }
        return ret;
    }
    
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        
        if (n == 0) {
            return 0;
        }
        
        if (n > m) {
            return -1;
        }

        if (needle == haystack.substr(0, n)) {
            return 0;
        }
        
        ll needleHash = calcHash(needle);
        ll haystackHash = calcHash(haystack.substr(0, n));
        ll baseToN = _power(26L, n - 1);
        ll modInv = _power(26LL, mod - 2LL);

        for (int i = n; i < m; i++) {
            haystackHash = ((haystackHash - (haystack[i - n] - 'a')) + mod) % mod;
            haystackHash = (haystackHash * modInv) % mod;
            haystackHash = (haystackHash +((haystack[i] - 'a') * baseToN) % mod) % mod;

            if (haystackHash == needleHash) {
                if (needle == haystack.substr(i - n + 1, n)) {
                    return i - n + 1;
                }
            }
        }
        
        return -1;
    }
};
