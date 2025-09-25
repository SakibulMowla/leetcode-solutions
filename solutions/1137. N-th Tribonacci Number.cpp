// Time - O(n)
// Memory - O(1)

class Solution {
public:
    int tribonacci(int n) {
        if (n <= 2)
            return n == 0 ? 0 : 1;
        
        int a = 0, b = 1, c = 1;
        for (int i = 3; i <= n; i++) {
            int tmp = a + b + c;
            a = b;
            b = c;
            c = tmp;
        }

        return c;
    }
};
