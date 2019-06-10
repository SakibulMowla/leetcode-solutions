class MyCalendarTwo {
public:
    vector<pair<int, int>> intervals;
    vector<pair<int, int>> calender;

    MyCalendarTwo() {
        intervals.clear();
        calender.clear();
    }
    
    bool book(int start, int end) {
        bool flag = true;
        for (auto& interval: calender) {
            if (interval.first >= end || interval.second <= start) {
                ;
            } else {
                return false;
            }
        }
        for (auto& interval: intervals) {
            if (interval.first >= end || interval.second <= start) {
                ;
            } else {
                calender.push_back({max(interval.first, start), min(end, interval.second)});
            }
        }
        intervals.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
