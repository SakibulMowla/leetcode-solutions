class Solution {
private:
    bool isTrueOrFalse(char ch) {
        return ch == 'T' || ch == 'F';
    }

public:
    string parseTernary(string expression) {
        stack<char> operands;
        for (int i = expression.size() - 1; i >= 0; i--) {
            char ch = expression[i];
            if (ch == '?') {
                char trueVal = operands.top();
                operands.pop();
                char falseVal = operands.top();
                operands.pop();

                operands.push(expression[i - 1] == 'T' ? trueVal : falseVal);
                i--;
            } else if (isdigit(ch) || isTrueOrFalse(ch)) {
                operands.push(ch);
            }
        }

        return string(1, operands.top());
    }
};
