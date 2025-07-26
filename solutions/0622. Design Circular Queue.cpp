class MyCircularQueue {
private:
    int capacity, size;
    int head, tail;
    vector<int> entries;
    shared_mutex queueMutex;

public:
    MyCircularQueue(int k): entries(k) {
        capacity = k;
        size = 0;  
        head = 0;
        tail = 0; 
    }
    
    bool enQueue(int value) {
        unique_lock lock(queueMutex);

        if (size == capacity)
            return false;

        entries[tail++] = value;
        size++;
        if (tail == capacity)
            tail = 0;
        
        return true;
    }
    
    bool deQueue() {
        unique_lock lock(queueMutex);

        if (size == 0)
            return false;
        
        head++;
        size--;
        if (head == capacity)
            head = 0;

        return true;
    }
    
    int Front() {
        shared_lock lock(queueMutex);

        if (size == 0)
            return -1;
        
        return entries[head];
    }
    
    int Rear() {
        shared_lock lock(queueMutex);

        if (size == 0)
            return -1;
        
        return entries[tail == 0 ? capacity - 1 : tail - 1];
    }
    
    bool isEmpty() {
        shared_lock lock(queueMutex);

        return size == 0;
    }
    
    bool isFull() {
        shared_lock lock(queueMutex);

        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
