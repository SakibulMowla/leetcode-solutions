class Solution {
private:
    int findIndex(string s, char ch) {
        int index = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == toupper(ch) || s[i] == tolower(ch)) {
                index = i;
                break;
            }
        }
        return index;
    }

    bool gotOnlyDigits(string& s, int start, int finish) {
        for (int i = start; i <= finish; i++) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
        }
        return true;
    }
    
    bool isDecimal(string s) {
        if (s.size() == 0) {
            return false;
        }
        if (s[0] == '+' || s[0] == '-') {
            s.erase(0, 1);
        }
        int n = s.size();
        int index = findIndex(s, '.');

        return index != -1 && gotOnlyDigits(s, 0, index - 1) && gotOnlyDigits(s, index + 1, n - 1) && (s.size() > 1);
    }
    
    bool isInteger(string s) {
        if (s.size() == 0) {
            return false;
        }
        if (s[0] == '+' || s[0] == '-') {
            s.erase(0, 1);
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
        }
        return s.size() > 0;
    }
    
    bool isValidChar(char ch) {
        return ch == 'e' || ch == 'E' || ch == '+' || ch == '-' || ch == '.' || (ch >= '0' && ch <= '9');
    }
    
    bool containsValidLetters(string s) {
        for (char ch: s) {
            if (!isValidChar(ch)) {
                return false;
            }
        }
        return true;
    }

public:
    bool isNumber(string s) {
        if (!containsValidLetters(s)) {
            return false;
        }
        
        int index = findIndex(s, 'e');
        if (index == -1) {
            return isDecimal(s) || isInteger(s);
        } else {
            string left = s.substr(0, index);
            string right = s.substr(index + 1);
            return (isDecimal(left) || isInteger(left)) &&  isInteger(right);
        }
    }
};
