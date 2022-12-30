class Solution {
private:
    bool isOperator(string& token) {
        return token == "+" ||
               token == "-" ||
               token == "*" ||
               token == "/";
    }

    int tokenToNumber(string& token) {
        int sign = 1;
        int number = 0;
        for (char ch: token) {
            if (ch == '-') {
                sign = -1;
            } else {
                number = number * 10 + (ch - '0');
            }
        }
        return number * sign;
    }

    int calculate(int a, int b, string& token) {
        if (token == "+") {
            return a + b;
        } else if (token == "-") {
            return a - b;
        } else if (token == "*") {
            return a * b;
        }
        return a / b;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for (string token: tokens) {
            if (isOperator(token)) {
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                int result = calculate(a, b, token);
                numbers.push(result);
            } else {
                numbers.push(tokenToNumber(token));
            }
        }
        return numbers.top();
    }
};
