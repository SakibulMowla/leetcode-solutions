class Solution {
private:
    vector<pair<int, string>> valueSymbolPair = {
        { 1, "I" },
        { 4, "IV" },
        { 5, "V" },
        { 9, "IX" },
        { 10, "X" },
        { 40, "XL" },
        { 50, "L" },
        { 90, "XC" },
        { 100, "C" },
        { 400, "CD" },
        { 500, "D" },
        { 900, "CM" },
        { 1000, "M" }
    };

public:
    string intToRoman(int num) {
        string ans;
        for (int i = valueSymbolPair.size() - 1; i >= 0; i--) {
            while (num >= valueSymbolPair[i].first) {
                ans +=  valueSymbolPair[i].second;
                num -= valueSymbolPair[i].first;
            }
        }
        return ans;
    }
};
