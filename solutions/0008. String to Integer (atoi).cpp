class Solution {
private:
    void removeLeadingZeros(string& s) {
        while (s.size() && s[0] == ' ') {
            s.erase(0, 1);
        }
        return;
    }
    
    bool isSignChar(char ch) {
        return ch == '+' || ch == '-';
    }

public:
    int myAtoi(string s) {
        removeLeadingZeros(s);
        if (s == "") {
            return 0;
        }
        
        long long absNum = 0;
        long long limit = 1LL + numeric_limits<int>::max();
    
        for (int i = (int)isSignChar(s[0]); i < s.size() && absNum <= limit; i++) {
            if (isdigit(s[i])) {
                absNum = absNum * 10L + (s[i] - '0');
            } else {
                break;
            }
        }
        
        long long num = s[0] == '-' ? absNum * -1 : absNum;
        
        if (num > numeric_limits<int>::max()) num = numeric_limits<int>::max();
        if (num < numeric_limits<int>::min()) num = numeric_limits<int>::min();
        
        return num;
    }
};
