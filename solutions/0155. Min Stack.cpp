class MinStack {
public:
    /** initialize your data structure here. */
    int stackSize;
    vector<int> myStack;
    vector<int> myMin;

    MinStack() {
        stackSize = 0;
        myStack.clear();
        myMin.clear();
    }
    
    void push(int x) {
        myStack.push_back(x);
        int currentMin = myMin.size() ? getMin() : numeric_limits<int>::max();
        if (x <= currentMin) {
            myMin.push_back(x);
        }
    }
    
    void pop() {
        if (top() == getMin()) {
            myMin.pop_back();
        }
        myStack.pop_back();
    }
    
    int top() {
        return myStack[myStack.size() - 1];
    }
    
    int getMin() {
        return myMin[myMin.size() - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 
// ================================================================

class MinStack {
private:
    stack<int> stk;
    stack<pair<int, int>> minStk;

public:
    /** initialize your data structure here. */
    MinStack() {
                
    }
    
    void push(int val) {
        stk.push(val);
        if (minStk.empty() || val < minStk.top().first) {
            minStk.push({ val, 1 });
        } else if (val == minStk.top().first) {
            pair<int, int> minStkTop = minStk.top();
            minStk.pop();
            minStkTop.second++;
            minStk.push(minStkTop);
        }
        
        return;
    }
    
    void pop() {
        if (minStk.top().first == stk.top()) {
            pair<int, int> minStkTop = minStk.top();
            minStk.pop();
            minStkTop.second--;
            if (minStkTop.second != 0) {
                minStk.push(minStkTop);   
            }
        }
        stk.pop();
        return;
    }
   
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
