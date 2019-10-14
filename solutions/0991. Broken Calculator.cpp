class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (Y <= X) {
            return X - Y;
        }
        if (Y % 2 == 0) {
            return 1 + brokenCalc(X, Y / 2);
        } else {
            return 2 + brokenCalc(X, (Y + 1) / 2);
        }
    }
};
