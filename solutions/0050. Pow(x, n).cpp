// Recursion
// Time - O(n)
// Memory - O(log n)

class Solution {
private:
    double myPowHelper(double x, long long n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;

        double half = myPowHelper(x, n / 2);
        return (n % 2) ? half * half * x : half * half;
    }

public:
    double myPow(double x, int n) {
        bool isNegative = (n < 0);
        double result = myPowHelper(x, labs(n));
        return isNegative ? 1.0 / result : result;
    }
};

// ---------------------------------------------------------------

// Iteration
// Time - O(n)
// Memory - O(1)

class Solution {
private:
    double myPowHelper(double x, long long n) {
        if (n == 0) return 1.0;

        double result = 1.0;
        while (n > 0) {
            // Multiply by x when the bit is 1 in binary representation
            if (n % 2 == 1) {
                result *= x;
            }
            x *= x;
            n /= 2;
        }

        return result;
    }

public:
    double myPow(double x, int n) {
        bool isNegative = (n < 0);
        double result = myPowHelper(x, labs(n));
        return isNegative ? 1.0 / result : result;
    }
};
