class Solution {
public:
    bool isValid(string s) {
        map<char, char> bracketPair;
        bracketPair['('] = ')';
        bracketPair['{'] = '}';
        bracketPair['['] = ']';
        stack<char> bracketPile;
        
        for (int i = 0; i < s.size(); i++) {
            if (bracketPair.find(s[i]) != bracketPair.end()) {
                bracketPile.push(s[i]);
            } else {
                if (bracketPile.size() == 0) {
                    return false;
                }
                char bracketOnTop = bracketPile.top();
                bracketPile.pop();
                if (bracketPair[bracketOnTop] != s[i]) {
                    return false;
                }
            }
        }
        
        return bracketPile.size() == 0;
    }
};
