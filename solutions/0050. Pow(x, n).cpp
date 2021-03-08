class Solution {
public:
    double absolutePower(double x, long long n) {
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return x;
        } else {
            double ans = absolutePower(x, n / 2);
            ans *= ans;
            if (n % 2 == 1) {
                ans *= x;
            }
            return ans;
        }
    }

    double myPow(double x, int n) {
        long long N = n;
        double ans = absolutePower(abs(x), abs(N));
        if (x < 0) {
            if (n % 2 == 1) {
                ans = -ans;
            }
        }
        if (n < 0) {
            ans = 1.0 / ans;
        }
        
        return ans;
    }
};
