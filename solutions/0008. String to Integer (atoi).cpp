class Solution {
private:
    void truncateWhitespaces(string& s) {
        int index = 0;
        while (index < s.size() && s[index] == ' ') {
            index++;
        }
        s = s.substr(index);
        return;
    }

    int sign(string& s) {
        if (s.size() == 0) {
            return 1;
        }

        int mul = s[0] == '-' ? -1 : 1;
        if (s[0] == '+' || s[0] == '-') {
            s = s.substr(1);
        }

        return mul;
    }

    long long conversion(string& s) {
        long long num = 0;
        for (char ch: s) {
            if (!isdigit(ch) || num >= numeric_limits<int>::max()) {
                break;
            }
            num = num * 10 + (ch - '0');
        }
        return num;
    }

    int rounding(long long num, int mul) {
        num *= mul;
        num = max(num, (long long)numeric_limits<int>::min());
        num = min(num, (long long)numeric_limits<int>::max());
        return (int)num;
    }

public:
    int myAtoi(string s) {
        truncateWhitespaces(s);
        int mul = sign(s);
        long long num = conversion(s);
        return rounding(num, mul);
    }
};

//--------------------------------------

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
