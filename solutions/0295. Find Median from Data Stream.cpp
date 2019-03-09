class MedianFinder {
public:
    /** initialize your data structure here. */
    
    int n;
    priority_queue<int> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;
    
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        n++;
        if (n & 1) {
            maxPQ.push(num);
        } else {
            minPQ.push(num);
        }
        if (minPQ.size()) {
            int minTop = minPQ.top();
            int maxTop = maxPQ.top();
            if (minTop < maxTop) {
                minPQ.pop();
                maxPQ.pop();
                minPQ.push(maxTop);
                maxPQ.push(minTop);
            }
        }
    }
    
    double findMedian() {
        if (!maxPQ.size() && !minPQ.size()) {
            return 0;
        }
        if (n & 1) {
            return maxPQ.top();
        } else {
            return (maxPQ.top() + minPQ.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
