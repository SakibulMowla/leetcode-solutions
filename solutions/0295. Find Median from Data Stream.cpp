class MedianFinder {
private:
    int size;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    /** initialize your data structure here. */
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if (size % 2 == 1) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }
        
        size++;
        
        if (size > 1 && maxHeap.top() > minHeap.top()) {
            int mx = maxHeap.top();
            maxHeap.pop();
            int mn = minHeap.top();
            minHeap.pop();
            
            maxHeap.push(mn);
            minHeap.push(mx);
        }
        
        return;
    }
    
    double findMedian() {
        if (size == 1) {
            return maxHeap.top();
        }
        return size % 2 == 1 ? maxHeap.top() : (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
