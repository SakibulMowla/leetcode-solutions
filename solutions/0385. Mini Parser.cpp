/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (isdigit(s[0])) {
            return NestedInteger(stoi(s));
        }

        int i = 0, n = s.size();
        stack<NestedInteger> stk;

        while (i < n) {
            if (s[i] == '[') {
                stk.push(NestedInteger());
                i++;
            } else if (s[i] == ',') {
                i++;
            } else if (s[i] == ']') {
                NestedInteger top = stk.top();
                stk.pop();

                if (stk.empty()) {
                    return top;
                }

                stk.top().add(top);
                i++;
            } else {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                stk.top().add(NestedInteger(num));
            }
        }

        return NestedInteger();
    }
};
