// Time - O(N)
// Memory - O(N)

class Solution {
private:
    void update(int& res, int& num, char opr) {
        if (opr == '-') {
            res -= num;
        } else {
            res += num;
        }

        num = 0;
        return;
    }

    int traverse(string& s, int& index) {
        int res = 0, num = 0;
        char opr = ' ';
        for (; index < s.size(); index++) {
            char ch = s[index];
            if (ch == ' ') {
                continue;
            } else if (ch == '(') {
                index++;
                num = traverse(s, index);
                update(res, num, opr);
            } else if (ch == ')') {
                update(res, num, opr);
                return res;
            } else if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else {
                update(res, num, opr);
                opr = ch;
            }
        }

        update(res, num, opr);

        return res;
    }

public:
    int calculate(string s) {
        int index = 0;
        return traverse(s, index);
    }
};

//--------------------------------------------------

// Time - O(N)
// Memory - O(N)

class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0;
        int sign = 1;

        stack<int> signs;
        signs.push(sign);

        for (char ch: s) {
            if (ch == ' ') {
                continue;
            } else if (ch == '(') {
                signs.push(sign);
            } else if (ch == ')') {
                signs.pop();
            } else if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else {
                res = res + num * sign;
                sign = (ch == '+' ? 1 : -1) * signs.top();
                num = 0;
            }
        }

        return res + num * sign;
    }
};
