class Solution {
public:
    
    int calc(int n) {
        int ret = 0;
        while (n) {
            int digit = n % 10;
            ret += digit * digit;
            n /= 10;
        }
        return ret;
    }

    bool isHappy(int n) {
        map<int, bool> found;
        while(true) {
            if (n == 1) {
                return true;
            }
            if (found.find(n) != found.end()) {
                break;
            }
            found[n] = true;
            n = calc(n);
        }
        return false;
    }
};
