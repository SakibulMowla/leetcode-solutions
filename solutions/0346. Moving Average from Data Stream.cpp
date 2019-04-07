class MovingAverage {
public:
    /** Initialize your data structure here. */
    int len;
    int sum;
    deque<int> deq;

    MovingAverage(int size) {
        len = size;
        sum = 0;
        deq.clear();        
    }
    
    double next(int val) {
        if (deq.size() == len) {
            int rem = deq.front();
            sum -= rem;
            deq.pop_front();
        }

        sum += val;
        deq.push_back(val);

        return 1.0 * sum / deq.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

