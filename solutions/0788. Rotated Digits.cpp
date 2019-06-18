class Solution {
public:
    map<int, int> rotated;
    
    int rotate(int n) {
        int ret = 0, ten = 1;
        while (n) {
            int digit = n % 10;
            if (rotated.find(digit) == rotated.end()) {
                return -1;
            }
            ret = ten * rotated[digit] + ret;
            ten *= 10;
            n /= 10;
        }
        return ret;
    }
    
    bool isGood(int n) {
        int inverse = rotate(n);
        return inverse > 0 && inverse != n;
    }

    int rotatedDigits(int N) {
        rotated[0] = 0;
        rotated[1] = 1;
        rotated[8] = 8;
        rotated[2] = 5;
        rotated[5] = 2;
        rotated[6] = 9;
        rotated[9] = 6;
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            ans += isGood(i);
        }
        return ans;
    }
};
