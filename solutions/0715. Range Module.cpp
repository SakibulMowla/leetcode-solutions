class RangeModule {
private:
using pii = pair<int, int>;
struct Comparator {
    bool operator() (const pii& a, const pii& b) const {
        return a.second < b.first;
    }
};
set<pii, Comparator> intervals;

public:
    RangeModule() {
        intervals.clear();
    }
    
    void addRange(int left, int right) {
        auto [begin, end] = intervals.equal_range({ left, right });
        if (begin != end) {
            left = min(begin->first, left);
            right = max(right, prev(end)->second);
            intervals.erase(begin, end);
        }
        intervals.insert({ left, right });
    }
    
    bool queryRange(int left, int right) {
        auto [begin, end] = intervals.equal_range({ left, right });
        return begin != end && left >= begin->first && right <= begin->second;
    }
    
    void removeRange(int left, int right) {
        auto [begin, end] = intervals.equal_range({ left, right });
        if (begin != end) {
            int beginFirst = begin->first;
            int endSecond = prev(end)->second;
            intervals.erase(begin, end);
            if (beginFirst < left) {
                intervals.insert({beginFirst, left});
            }
            if (endSecond > right) {
                intervals.insert({right, endSecond});
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
