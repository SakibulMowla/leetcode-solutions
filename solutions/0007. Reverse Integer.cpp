// Using int

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        int MAX = numeric_limits<int>::max();
        int MIN = numeric_limits<int>::min();

        while (x) {
            int digit = x % 10;
            x /= 10;
            if (ans > MAX / 10 || (ans == MAX / 10 && digit > 7)) {
                return 0;
            }
            if (ans < MIN / 10 || (ans == MIN / 10 && digit < -8)) {
                return 0;
            }
            
            ans = ans * 10 + digit;
        }

        return ans;
    }
};

// -------------------------------------------------

// Using long long

class Solution {
private:
    long long absoluteReverse(int x) {
        long long ans = 0;
        while (x) {
            ans = ans * 10 + (x % 10);
            x /= 10;
        }
        return ans;
    }

public:
    int reverse(int x) {
        long long absReverse = absoluteReverse(x);

        return ((absReverse > numeric_limits<int>::max()) ||
                (absReverse < numeric_limits<int>::min()))
                   ? 0
                   : absReverse;
    }
};
