class Solution {
public:
    char rotate(char ch) {
        if (ch == '0' || ch == '1' || ch == '8') return ch;
        if (ch == '6') return '9';
        if (ch == '9') return '6';
        return 'x';
    }

    bool isStrobogrammatic(string num) {
        int n = num.size();
        string prime;
        for (int i = n - 1; i >= 0; i--) {
            prime += rotate(num[i]);
        }
        return num == prime;
    }
};
