class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            unsigned int carry = (a & b) << 1;
            a = a ^ b;
            b = (int)carry;
        }
        return a;
    }
};
