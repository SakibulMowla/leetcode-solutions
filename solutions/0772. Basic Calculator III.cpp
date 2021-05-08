class Solution {
private:
    unordered_map<char, int> precedence = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2}
    };
    
    void calcSingleRes(stack<int>& nums, stack<char>& ops) {
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        
        char op = ops.top();
        ops.pop();
        
        int res;
        
        switch (op) {
            case '+':
                res = a + b;
                break;
            case '-':
                res = a - b;
                break;
            case '*':
                res = a * b;
                break;
            case '/':
                res = a / b;
                break;
        }
        
        nums.push(res);
        return;
    }
    
    int dfs(string& s, int& pos) {
        stack<int> nums;
        stack<char> ops;
        int cur = 0;
        for (; pos < s.size(); pos++) {
            if (s[pos] == '(') {
                pos++;
                cur = dfs(s, pos);
            } else if (s[pos] == ')') {
                break;
            } else if (precedence.find(s[pos]) != precedence.end()) {
                nums.push(cur);
                cur = 0;
                
                char op = s[pos];
                while (!ops.empty() && precedence[ops.top()] >= precedence[op]) {
                    calcSingleRes(nums, ops);
                }
                ops.push(op);
            } else {
                cur = cur * 10 + (s[pos] - '0');
            }
        }
        nums.push(cur);
        
        while (!ops.empty()) {
            calcSingleRes(nums, ops);
        }
        
        return nums.top();
    }

public:
    int calculate(string s) {
        int pos = 0;
        return dfs(s, pos);
    }
};
