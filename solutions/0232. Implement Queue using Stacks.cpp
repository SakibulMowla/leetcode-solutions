class MyQueue {
private:
    stack<int> stackStore, stackRetrieve;
    void transfer() {
        while (!stackStore.empty()) {
            stackRetrieve.push(stackStore.top());
            stackStore.pop();
        }
        return;
    }

public:
    MyQueue() {
        while(!stackStore.empty()) {
            stackStore.pop();
        } 
        while(!stackRetrieve.empty()) {
            stackRetrieve.pop();
        }    
    }
    
    void push(int x) {
        stackStore.push(x);
    }
    
    int pop() {
        int top = peek();
        stackRetrieve.pop();
        return top;
    }
    
    int peek() {
        if (stackRetrieve.empty()) {
            transfer();
        }
        return stackRetrieve.top();
    }
    
    bool empty() {
        return stackStore.empty() && stackRetrieve.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
