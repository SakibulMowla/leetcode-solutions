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
 
