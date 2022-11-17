class Solution {
private:
    unordered_map<char, char> complement = {
        { '(', ')' },
        { '{', '}' },
        { '[', ']' }
    };
 
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char ch: s) {
            if (complement.find(ch) != complement.end()) {
                stk.push(ch);
            } else {
                if (stk.empty()) {
                    return false;
                }
                char top = stk.top();
                stk.pop();
                if (complement[top] != ch) {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};
