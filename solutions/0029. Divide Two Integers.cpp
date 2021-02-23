// ================== Divide and Conquer ==================

class Solution {
public:
    using ll = long long;
    
    pair<ll, ll> divideAndConquer(ll dividend, ll divisor) {
        if (dividend == 0) {
            return { 0, 0 };
        }
        
        pair<ll, ll> res = divideAndConquer(dividend >> 1, divisor);
        pair<ll, ll> ret = { 0, 0 };
        ll odd = (dividend & 1);
        
        ret.first = res.first + res.first;
        if (res.second + res.second + odd < divisor) {
            ret.second = res.second + res.second + odd;
        } else if (res.second + res.second + odd == divisor) {
            ret.first += 1;
        } else {
            ret.first += 1;
            ret.second = res.second + res.second + odd - divisor;
        }
        
        return ret;
    }
    
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -1) {
            return 2147483647;
        }
        
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        pair<ll, ll> res = divideAndConquer(abs(dividend), abs(divisor));
        
        return isNegative ? -res.first : res.first;
    }
};

// ================== Bitwise Operation ==================

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == numeric_limits<int>::min() && divisor == -1)) 
            return numeric_limits<int>::max();
        
        int sign = ((dividend < 0) ^ (divisor < 0)) ? 0 : 1;
        long long num = dividend, den = divisor, got = 0;
        num = abs(num);
        den = abs(den);
        int ans = 0;
        
        for (int i = 31; i >= 0; i--) {
            if (got + (den << i) <= num) {
                got += (den << i);
                ans += (1 << i);
            }
        }
        
        return sign ? ans : -ans;
    }
};
