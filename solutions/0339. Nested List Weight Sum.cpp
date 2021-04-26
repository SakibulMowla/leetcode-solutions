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


// ==============================================
// ================= BFS ========================
// ==============================================

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> q;
        
        for (auto element: nestedList) {
            q.push(element);
        }
        
        int depth = 1;
        int ans = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            
            for (int i = 0; i < sz; i++) {
                auto front = q.front();
                q.pop();
                
                if (front.isInteger()) {
                    ans += front.getInteger() * depth;
                } else {
                    for (auto element: front.getList()) {
                        q.push(element);
                    }
                }
            }
            
            depth++;
        }
        
        return ans;
    }
};

// ==============================================
// ================= DFS ========================
// ==============================================

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList, int depth = 1) {
        int ans = 0;
        int curDepthSum = 0;

        for (int i = 0; i < nestedList.size(); i++) {
            if (nestedList[i].isInteger()) {
                curDepthSum += nestedList[i].getInteger();
            } else {
                ans += depthSum(nestedList[i].getList(), depth + 1);
            }
        }
        
        return ans + curDepthSum * depth;
    }
};
