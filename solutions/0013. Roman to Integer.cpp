// =============================================
// Left to Right (---------------------------->)
// =============================================

class Solution {
private:
    unordered_map<string, int> symbolToValue = {
        { "I", 1 },
        { "V", 5 },
        { "X", 10 },
        { "L", 50 },
        { "C", 100 },
        { "D", 500 },
        { "M", 1000 },
        { "IV", 4 },
        { "IX", 9 },
        { "XL", 40 },
        { "XC", 90 },
        { "CD", 400 },
        { "CM", 900 }
    };
public:
    int romanToInt(string s) {
        int index = 0;
        int n = s.size();
        int ans = 0;

        while (index < n) {
            if (index + 1 < n && symbolToValue.find(s.substr(index, 2)) != symbolToValue.end()) {
                ans += symbolToValue[s.substr(index, 2)];
                index += 2;
            } else {
                ans += symbolToValue[s.substr(index, 1)];
                index++;
            }
        }
        
        return ans;
    }
};

// =============================================
// Right to Left (<----------------------------)
// =============================================

class Solution {
private:
    unordered_map<char, int> symbolToValue = {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 }
    };

public:
    int romanToInt(string s) {
        int index = 0;
        int n = s.size();
        int ans = symbolToValue[s[n - 1]];
        int prev = ans;
        
        for (int i = n - 2; i >= 0; i--) {
            int current = symbolToValue[s[i]];
            if (current < prev) {
                ans -= current;
            } else {
                ans += current;
            }
            prev = current;
        }
        
        return ans;
    }
};
