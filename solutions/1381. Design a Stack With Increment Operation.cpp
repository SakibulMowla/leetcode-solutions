class CustomStack {
private:
    int capacity;
    int index;
    vector<int> entries, addition;

public:
    CustomStack(int maxSize) {
        capacity = maxSize;
        index = -1;
        entries.resize(capacity);    
        addition.resize(capacity);
    }
    
    void push(int x) {
        if (index == capacity - 1)
            return;

        entries[++index] = x;
    }
    
    int pop() {
        if (index == -1)
            return -1;

        int ret = entries[index] + addition[index];
        if (index)
            addition[index - 1] += addition[index];
        addition[index] = 0;
        index--;

        return ret;
    }
    
    void increment(int k, int val) {
        if (index == -1)
            return;
            
        int point = min(k - 1, index);
        addition[point] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
